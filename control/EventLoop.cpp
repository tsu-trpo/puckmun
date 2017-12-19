#include "control/EventLoop.h"

EventLoop :: EventLoop(const GameField& field, const InputList& inputs)
	: m_field (field)
	, m_inputs(inputs)
{}


// updates object by the command send by input/AI
void EventLoop :: update_object_plan(const Command& command, const shared_ptr<AnimateObject>& object)
{
	command.update(object);
}


// start and run the game - the main event loop
EventLoop& EventLoop :: start_game()
{
	while(m_keep_playing)
	{
		this->redraw_screen();

		// replan all objects' actions
		for (auto& t : m_inputs)
		{
			auto& input_ptr  = t.first;
			auto& object_ptr = t.second;

			auto command = input_ptr->plan(m_field, object_ptr);

			this->update_object_plan(command, object_ptr);
		}

		this->animate_objects(); //sets to keep playing
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


PeriodT EventLoop :: increment_tick()
{
	// maximum is 120, which is divisible by 1, 2, 3, 4, 5, 6, 8, 10, 12
	return m_current_tick = (m_current_tick + 1) % 120;
}


//decide where to move all objects according to physics
//returns new value of m_keep_playing
bool EventLoop :: animate_objects()
{
	for (auto& object : m_field.get_objects())
	{
		// every periodth time of object do
		if ( m_current_tick % object->get_period() == 0 )
		{
			MoveDirection dir = object->tick();
//			this->move_object(dir, object);
		}
	}
}
