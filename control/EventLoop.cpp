#include "control/EventLoop.h"

EventLoop :: EventLoop(GameField field, InputList inputs)
	: m_field (field)
	, m_inputs(inputs)
{}


void EventLoop :: plan_object(const Command& command, const shared_ptr<AnimateObject>& object)
{
	command.update(object);
}


EventLoop& EventLoop :: start_game()
{
	while(m_keep_playing)
	{
		this->move_objects();

		this->redraw_screen();

		for (auto& t : m_inputs)
		{
			auto& input_ptr  = t.first;
			auto& object_ptr = t.second;

			auto command = input_ptr->plan(m_field, object_ptr);

			this->plan_object(command, object_ptr);
		}
	}
}


EventLoop& EventLoop :: run() //updates everything
{
	this->before_game()
		 .start_game()
		 .after_game();
	return *this;
}
