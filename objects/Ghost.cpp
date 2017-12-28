#include "objects/Ghost.h"

Ghost::Ghost()
{
	m_current = MoveDirection::Down;
}
MoveDirection Ghost::tick() 
{
	return m_current;
}
Ghost & Ghost::set_current(MoveDirection next)
{
	m_current = next;
	return *this;
}

char Ghost::get_form() const
{
	return 'M';
}

Color Ghost::get_bg_color() const
{
	return Color::Black;
}

Color Ghost::get_body_color() const
{
	return Color::Cyan;
}

GameObject& Ghost::promote()
{
	return *this;
}

GameObject& Ghost::demote()
{
	return *this;
}

MoveDirection Ghost::get_current() const
{
	return m_current;
}

bool Ghost::eats_points() const
{
	return false;
}
