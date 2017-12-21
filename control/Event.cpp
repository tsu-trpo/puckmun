#include "control/Event.h"

Event::Event(unique_ptr<BaseEvent> event)
	: m_event (std::move(event))
{
}

void Event::execute_physics(GameField& field) const
{
	m_event->execute_physics(field);
}

void Event::execute_graphics(const GameField& field, Render& render) const
{
	m_event->execute_graphics(field, render);
}

bool Event::graphics_first() const
{
	return m_event->graphics_first();
}
