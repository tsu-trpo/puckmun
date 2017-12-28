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
        return m_future;
}

char TheMan::get_form() const
{
	char k=' ';
	return k;
}

Color TheMan::get_bg_color() const
{
	return Color::Yellow;
}

Color TheMan::get_body_color() const
{
	return Color::Yellow;
}

GameObject& TheMan::promote()
{
	return *this;
}
GameObject& TheMan::demote()
{
	return *this;
}

bool TheMan::eats_points() const
{
	return true;
}
