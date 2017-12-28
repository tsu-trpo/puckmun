#include "control/EventLoop.h"

#include "errors/ErrorConstants.h"

EventLoop :: EventLoop(
	const GameField& field,
	const InputList& inputs,
	GameRender& render
	)
	: m_field (field)
	, m_inputs(inputs)
	, m_render(std::move(render))
	, m_keep_playing (true)
	, m_current_tick (0)
	, m_current_time (0)
	, m_scheduled_events {}
{}


// start and run the game - the main event loop
EventLoop& EventLoop :: start_game()
{
	while(m_keep_playing)
	{
		this->replan_all_objects();

		// tick all objects and act upon it
		for (auto& object_ptr : m_field.objects)
		{
			// every periodth time of object do
			if ( m_current_tick % object_ptr->get_period() != 0 )
			{
				continue;
			}
			// get desired movement
			MoveDirection dir = object_ptr->tick();
			// handle movement events
			auto events = Physics::move_object(m_field, object_ptr, dir);
			// commit movement events
			this->move_and_redraw(events);
		}

		this->increment_tick();
	}

	return *this;
}


// take actions before running the event loop
EventLoop& EventLoop :: before_game()
{
	m_render.redraw_complete(m_field);
	return *this;
}


// take actions after the event loop peacefully terminates
EventLoop& EventLoop :: after_game()
{
	return *this;
}


// public functions to set up all actions of event loop
EventLoop& EventLoop :: run() //updates everything
{
	this->before_game()
	     .start_game()
	     .after_game();
	return *this;
}


EventLoop& EventLoop :: replan_all_objects()
{
	for (auto& t : m_inputs)
	{
		auto& input_ptr  = t.first;
		auto& object_ptr = t.second;

		auto command = input_ptr->plan(m_field, object_ptr);
		command.update(object_ptr);
	}
	return *this;
}


EventLoop& EventLoop :: move_and_redraw(const PhysicsEvents& events)
{
	// execute immediate events
	for (auto& event : events.immediate)
	{
		this->execute_one_event(event);
	}

	// schedule delayed events
	for (auto& event : events.delayed)
	{
		m_scheduled_events.push_back(event);
		// make the time absolute
		m_scheduled_events.back().time += m_current_time;
	}

	// execute scheduled events
	for (auto event_it = m_scheduled_events.begin();
	     event_it != m_scheduled_events.end();
	     ++event_it)
	{
		if (event_it->time == m_current_time)
		{
			this->execute_one_event(event_it->event);

			// safely erase element
			auto to_erase = event_it--;
			m_scheduled_events.erase(to_erase);
			//now ++event_it will go to the correct element after deleted
		}
	}

	return *this;
}


EventLoop& EventLoop :: execute_one_event(const Event& event)
{
	if (event.graphics_first())
	{
		event.execute_graphics(m_field, m_render);
		event.execute_physics(m_field);
	}
	else
	{
		event.execute_physics(m_field);
		event.execute_graphics(m_field, m_render);
	}
	return *this;
}


PeriodT EventLoop :: increment_tick()
{
	m_current_time += 1;
	m_current_tick = (m_current_tick + 1) % MaxPeriod;
	return m_current_tick;
}

// vim: tw=78
