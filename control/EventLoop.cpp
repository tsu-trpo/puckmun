#include "control/EventLoop.h"

#include "error.h"

EventLoop :: EventLoop(const GameField& field, const InputList& inputs)
	: m_field (field)
	, m_inputs(inputs)
{}


// start and run the game - the main event loop
EventLoop& EventLoop :: start_game()
{
	while(m_keep_playing)
	{
		this->replan_all_objects();

		// move and redraw each object based on tick
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
			vector<Event> events = this->move_object(dir, object_ptr);
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


EventLoop& EventLoop :: move_and_redraw(const vector<Event>& events)
{
	for (auto& event : events)
	{
		//drawing stuff
		this->redraw_screen(event);
		//physics stuff
		this->execute_event(event);
	}
	return *this;
}


PeriodT EventLoop :: increment_tick()
{
	// maximum is 120, which is divisible by 1, 2, 3, 4, 5, 6, 8, 10, 12
	return m_current_tick = (m_current_tick + 1) % 120;
}

EventLoop& EventLoop :: execute_event(const Event& event)
{
	if (event.get_type() == Event::Type::Nothing)
	{
		return *this;
	}
	if (event.get_type() == Event::Type::EatPoint)
	{
		auto x = event.get_coordinate_argument_x();
		auto y = event.get_coordinate_argument_y();

		m_field.map.change_block(x, y, Block::Space);

		//TODO: score stuff

		return *this;
	}
	if (event.get_type() == Event::Type::DestroyWall)
	{
		auto x = event.get_coordinate_argument_x();
		auto y = event.get_coordinate_argument_y();

		m_field.map.change_block(x, y, Block::Space);

		return *this;
	}
	if (event.get_type() == Event::Type::AddWall)
	{
		auto x     = event.get_coordinate_argument_x();
		auto y     = event.get_coordinate_argument_y();
		auto block = event.get_block_argument();

		m_field.map.change_block(x, y, block);

		return *this;
	}
}
// vim: tw=78
