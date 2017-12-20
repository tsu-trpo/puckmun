#include "objects/TheMan.h"

TheMan::TheMan()
{
	m_current = MoveDirection::Down;
	m_future = MoveDirection::Down;
}
MoveDirection TheMan::tick()
{
	return m_current;
}

void TheMan::set_current()
{
	m_current = m_future;
}

void TheMan::set_future(MoveDirection next)
{
	m_future = next;
}

MoveDirection TheMan::get_current() const
{
	return m_current;
}

MoveDirection TheMan::get_future() const
{
        return m_current;
}

