#include "objects/TheMan.h"

TheMan::TheMan()
{
	m_current = MoveDirection::Down;
}
MoveDirection TheMan::tick()
{
	return m_current;
}

void TheMan::set_current(MoveDirection dir)
{
	m_current = dir;
}

MoveDirection TheMan::get_current() const
{
	return m_current;
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
