#include "objects/Ghost.h"

#include "control/Event.h"

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

Event Ghost::touch(shared_ptr<const TactileObject> other) const
{
	return other->touch(shared_from_this());
}


Event Ghost::touch(shared_ptr<const TheMan>) const
{
	// ghost eats dude, nom nom nom
	return Events::make_die_hero();
}

Event Ghost::touch(shared_ptr<const Ghost>) const
{
	// ghost hails the other ghost with a breezy wave
	return Events::make_nothing();
}
