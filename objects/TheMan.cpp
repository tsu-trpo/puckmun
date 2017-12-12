#include "objects/TheMan.h"

TheMan::TheMan()
{
	m_current = NULL;
	m_next = NULL;
}
MoveDirection TheMan::tick()
{
	return m_current;
}
