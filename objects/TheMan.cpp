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
