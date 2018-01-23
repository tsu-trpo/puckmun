#include "control/EventLoop.h"

#include <fstream>
#include <thread>
#include <chrono>

#include "errors/ErrorConstants.h"

std::ofstream log ("logfile.log");

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
	log << "time: " << m_current_time <<"; ";
	log << "started game\n";
	log.flush();
	while(m_keep_playing)
	{
		log << "time: " << m_current_time <<"; ";
		log << "replanning all objects\n";
		log.flush();
		this->replan_all_objects();
		log << "time: " << m_current_time <<"; ";
		log << "done\n";
		log.flush();

		log << "time: " << m_current_time <<"; ";
		log << "ticking objects\n";
		log.flush();
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
		log << "time: " << m_current_time <<"; ";
		log << "done\n";
		log.flush();

		this->increment_tick();
	}

	return *this;
}


// take actions before running the event loop
EventLoop& EventLoop :: before_game()
{
	log << "time: " << m_current_time <<"; ";
	log << "before game\n";
	log.flush();
	m_render.redraw_complete(m_field);
	log << "time: " << m_current_time <<"; ";
	log << "field redrawn\n";
	log.flush();
	return *this;
}


// take actions after the event loop peacefully terminates
EventLoop& EventLoop :: after_game()
{
	// delete all inputs so noone reads from screen
	m_inputs.resize(0);
	std::this_thread::sleep_for(std::chrono::seconds(3));
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
	log << "time: " << m_current_time <<"; ";
	log << "executing immediate events\n";
	log.flush();
	for (auto& event : events.immediate)
	{
		this->execute_one_event(event);
	}

	log << "time: " << m_current_time <<"; ";
	log << "scheduling events\n";
	log.flush();
	// schedule delayed events
	for (auto& event : events.delayed)
	{
		m_scheduled_events.push_back(event);
		// make the time absolute
		m_scheduled_events.back().time += m_current_time;
	}

	log << "time: " << m_current_time <<"; ";
	log << "executing scheduled events\n";
	log.flush();
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
	log << "time: " << m_current_time <<"; ";
	log << "executing single event\n";
	log.flush();
	if (event.graphics_first())
	{
		event.execute_graphics(m_field, m_render);
		GameStatus status = event.execute_physics(m_field);
		this->check_status(status);
	}
	else
	{
		GameStatus status = event.execute_physics(m_field);
		event.execute_graphics(m_field, m_render);
		this->check_status(status);
	}
	return *this;
}


PeriodT EventLoop :: increment_tick()
{
	log << "time: " << m_current_time <<"; ";
	log << "moving to next tick\n";
	log.flush();
	m_current_time += 1;
	m_current_tick = (m_current_tick + 1) % MaxPeriod;
	return m_current_tick;
}

EventLoop& EventLoop::check_status(const GameStatus& status)
{
	switch (status)
	{
		case GameStatus::Continue:
			return *this;
		case GameStatus::Lost:
			m_render.print_status("You lost!");
			m_keep_playing = false;
			return *this;
		case GameStatus::Won:
			m_render.print_status("You won!");
			m_keep_playing = false;
			return *this;
	}
	throw std::logic_error(ERR_HEADER "unexpected game status");
}

// vim: tw=78
