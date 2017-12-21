#include "objects/Ghost.h"

Ghost::Ghost()
{
	m_current = MoveDirection::Down;
}
MoveDirection Ghost::tick()
{
	return m_current;
}
void Ghost::Change_Current(MoveDirection next)
{
		m_current = next;
}
