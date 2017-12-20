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

void move_one_object(const shared_ptr<AnimateObject>& obj, MoveDirection dir)
{
	// doesn't check for boundaries because it doesn't have enought
	// information for right limit anyway, and it should be called only in
	// correct cases by design

	switch (dir)
	{
		case MoveDirection::Up:
			obj->set_y( obj->get_y() - 1 );
			return;
		case MoveDirection::Down:
			obj->set_y( obj->get_y() + 1 );
			return;
		case MoveDirection::Left:
			obj->set_x( obj->get_x() - 1 );
			return;
		case MoveDirection::Right:
			obj->set_x( obj->get_x() + 1 );
			return;
	}
}

EventLoop& EventLoop :: execute_event(const Event& event)
{
	switch (event.get_type())
	{
	case Event::Type::Nothing:
	{
		return *this;
	}
	case Event::Type::EatPoint:
	{
		auto x = event.get_coordinate_argument_x();
		auto y = event.get_coordinate_argument_y();

		m_field.map.change_block(x, y, Block::Space);

		//TODO: score stuff

		return *this;
	}
	case Event::Type::DestroyWall:
	{
		auto x = event.get_coordinate_argument_x();
		auto y = event.get_coordinate_argument_y();

		m_field.map.change_block(x, y, Block::Space);

		return *this;
	}
	case Event::Type::AddWall:
	{
		auto x     = event.get_coordinate_argument_x();
		auto y     = event.get_coordinate_argument_y();
		auto block = event.get_block_argument();

		m_field.map.change_block(x, y, block);

		return *this;
	}
	case Event::Type::Move:
	{
		auto dir    = event.get_direction_argument();
		auto object = event.get_object_argument();

		move_one_object(object, dir);

		return *this;
	}
	// TODO: other cases
	}
}
// vim: tw=78
