#include "objects/Ghost.h"

#include "control/Physics.h"
#include "objects/TheMan.h"
#include "control/Event.h"

const PhysicsEvents NoEvents =
	PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

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

bool Ghost::eats_points() const
{
	return false;
}

PhysicsEvents Ghost::touch(shared_ptr<const TactileObject> other) const
{
	return other->touch(shared_from_this());
}


PhysicsEvents Ghost::touch(shared_ptr<const TheMan> man_ptr) const
{
	if (man_ptr->get_promoted())
	{
		return NoEvents;
	}
	else
	{
		// ghost eats dude, nom nom nom
		return { {Events::make_die_hero()}, {} };
	}
}

PhysicsEvents Ghost::touch(shared_ptr<const Ghost>) const
{
	// ghost hails the other ghost with a breezy wave
	return NoEvents;
}
