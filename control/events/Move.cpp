#include "control/events/Move.h"

Events::Move::Move(const shared_ptr<GameObject>& obj, MoveDirection dir)
	: m_direction (dir)
	, m_object    (obj)
{
	// doesn't check for boundaries because it doesn't have enough
	// information for right limit anyway, and it should be called only in
	// correct cases by design
	switch (m_direction)
	{
		case MoveDirection::Up:
			m_new_y = m_object->get_y() - 1;
			break;
		case MoveDirection::Down:
			m_new_y = m_object->get_y() + 1;
			break;
		case MoveDirection::Left:
			m_new_x = m_object->get_x() - 1;
			break;
		case MoveDirection::Right:
			m_new_x = m_object->get_x() + 1;
			break;
	}
}

void Events::Move::execute_physics(GameField& f) const
{
	m_object->set_x(m_new_x);
	m_object->set_y(m_new_y);
}

void Events::Move::execute_graphics(const GameField& field, Render& r) const
{
	r.redraw_object_pre_move(field, *m_object, m_new_x, m_new_y);
}

bool Events::Move::graphics_first() const
{
	return true;
}
// vim: tw=78
