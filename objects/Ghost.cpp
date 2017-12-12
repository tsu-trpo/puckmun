#include "objects/Ghost.h"

Ghost::Ghost()
{
	m_current = NULL;
}
MoveDirection Ghost::tick()
{
	return m_current;
}
