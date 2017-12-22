#include "control/events/Demote.h"

Events::Demote::Demote(const shared_ptr<GameObject>& object)
	: m_object (object)
{
}

std::unique_ptr<BaseEvent> Events::Demote::clone() const
{
	return unique_ptr<BaseEvent>( new Demote(*this) );
}

void Events::Demote::execute_physics(GameField&) const
{
	m_object->demote();
}

void Events::Demote::execute_graphics(const GameField& f, GameRender& r) const
{
	r.redraw_object_nomove(f, *m_object);
}

bool Events::Demote::graphics_first() const
{
	return false;
}
// vim: tw=78
