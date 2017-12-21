#include "objects/Ghost.h"

Ghost::Ghost()
{
	m_current = MoveDirection::Down;
}
MoveDirection Ghost::tick()
{
	return m_current;
}
void Ghost::change_current(MoveDirection next)
{
		m_current = next;
}
