#include "control/events/Move.h"

#include <fstream>

static std::ofstream log ("move.log");

Events::Move::Move(const shared_ptr<GameObject>& obj, MoveDirection dir)
	: m_direction (dir)
	, m_object    (obj)
{
	// doesn't check for boundaries because it doesn't have enough
	// information for right limit anyway, and it should be called only in
	// correct cases by design
	m_new_x = m_object->get_x();
	m_new_y = m_object->get_y();
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
	log << "created move event: " << m_new_x <<':' << m_new_y << std::endl;
}

std::unique_ptr<BaseEvent> Events::Move::clone() const
{
	return unique_ptr<BaseEvent>( new Move(*this) );
}

void Events::Move::execute_physics(GameField&) const
{
	m_object->set_x(m_new_x);
	m_object->set_y(m_new_y);
}

void Events::Move::execute_graphics(const GameField& field, GameRender& r) const
{
	r.redraw_object_pre_move(field, *m_object, m_new_x, m_new_y);
}

bool Events::Move::graphics_first() const
{
	return true;
}
// vim: tw=78
