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
	// dude dies, sad sad sad
	return Events::make_die_hero();
}
