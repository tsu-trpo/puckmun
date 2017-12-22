#include "control/events/Promote.h"

Events::Promote::Promote(const shared_ptr<GameObject>& object)
	: m_object (object)
{
}

std::unique_ptr<BaseEvent> Events::Promote::clone() const
{
	return unique_ptr<BaseEvent>( new Promote(*this) );
}

void Events::Promote::execute_physics(GameField&) const
{
	m_object->promote();
}

void Events::Promote::execute_graphics(const GameField& f, Render& r) const
{
	r.redraw_object_nomove(f, *m_object);
}

bool Events::Promote::graphics_first() const
{
	return false;
}
// vim: tw=78
