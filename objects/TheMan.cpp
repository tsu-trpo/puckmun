#include "objects/TheMan.h"

TheMan::TheMan()
	: m_promoted (false)
	, m_bg_color (Color::Yellow)
	, m_fg_color (Color::Yellow)
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
	return m_bg_color;
}

Color TheMan::get_body_color() const
{
	return m_fg_color;
}

GameObject& TheMan::promote()
{
	m_promoted = true;
	m_bg_color = Color::Red;
	m_fg_color = Color::Red;
	return *this;
}
GameObject& TheMan::demote()
{
	m_promoted = false;
	m_bg_color = Color::Yellow;
	m_fg_color = Color::Yellow;
	return *this;
}

bool TheMan::eats_points() const
{
	return true;
}

Event TheMan::touch(shared_ptr<const TactileObject> other) const
{
	return other->touch(shared_from_this());
}


Event TheMan::touch(shared_ptr<const TheMan>) const
{
	// dudes interact with a high five and nothing more
	return Events::make_nothing();
}

Event TheMan::touch(shared_ptr<const Ghost>) const
{
	if (m_promoted)
	{
		// whoah, cool dude doesnt care
		return Events::make_nothing();
	}
	else
	{
		// dude dies, sad sad sad
		return Events::make_die_hero();
	}
}

bool TheMan::get_promoted() const
{
	return m_promoted;
}
