#include "objects/TheMan.h"

TheMan::TheMan()
{
	m_current = MoveDirection::Down;
	m_next = MoveDirection::Down;
}
MoveDirection TheMan::tick()
{
	return m_current;
}

void TheMan::Change_Current()
{
	m_current = m_next;
}

void TheMan::Change_Next(MoveDirection next)
{
	m_next = next;
}
