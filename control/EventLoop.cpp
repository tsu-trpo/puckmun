#include "control/EventLoop.h"

EventLoop :: EventLoop(const GameField& field, const InputList& inputs)
	: m_field (field)
	, m_inputs(inputs)
{}


// updates object by the command send by input/AI
void EventLoop :: update_object_plan(const Command& command, const shared_ptr<GameObject>& object)
{
	command.update( std::static_pointer_cast<AnimateObject>(object) );
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

		this->move_objects();
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
