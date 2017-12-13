#include "objects/TheMan.h"

TheMan::TheMan()
{
	m_current = Down;
	m_next = Down;
}
MoveDirection TheMan::tick()
{
	return m_current;
}
