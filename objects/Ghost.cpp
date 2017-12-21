#include "objects/Ghost.h"

Ghost::Ghost()
{
	m_current = MoveDirection::Down;
}
MoveDirection Ghost::tick()
{
	return m_current;
}
