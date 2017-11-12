#include "control/EventLoop.h"

EventLoop :: EventLoop(GameField field, InputList inputs)
	: m_field (field)
	, m_inputs(inputs)
{}


EventLoop& EventLoop :: start_game()
{
	while(m_keep_playing)
	{
		this->update_objects();

		this->redraw_screen();

		for (auto& input_ptr : m_inputs)
		{
			input_ptr->update(m_field);
		}
	}
}
