#include "objects/Ghost.h"

Ghost::Ghost()
{
	m_current = Down;
}
MoveDirection Ghost::tick()
{
	return m_current;
}
