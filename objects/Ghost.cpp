#include "objects/Ghost.h"

#include "control/Physics.h"
#include "objects/TheMan.h"
#include "control/Event.h"
#include "control/Interactions.h"

const PhysicsEvents NoEvents =
	PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

Ghost::Ghost()
	: m_demoted (false)
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
	m_demoted = false;
	return *this;
}

GameObject& Ghost::demote()
{
	m_demoted = true;
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

PhysicsEvents Ghost::touch(const shared_ptr<TactileObject>& other)
{
	return other->touch(shared_from_this());
}


PhysicsEvents Ghost::touch(const shared_ptr<TheMan>& man_ptr)
{
	return Physics::ghost_man_interaction(shared_from_this(), man_ptr);
}

PhysicsEvents Ghost::touch(const shared_ptr<Ghost>&)
{
	// ghost hails the other ghost with a breezy wave
	return NoEvents;
}

bool Ghost::get_demoted() const
{
	return m_demoted;
}
