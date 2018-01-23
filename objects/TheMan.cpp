#include "objects/TheMan.h"

#include "objects/GameObject.h"
#include "objects/Ghost.h"
#include "control/Physics.h"
#include "control/Interactions.h"

const PhysicsEvents NoEvents =
	PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

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

PhysicsEvents TheMan::touch(const shared_ptr<TactileObject>& other)
{
	return other->touch(shared_from_this());
}


PhysicsEvents TheMan::touch(const shared_ptr<TheMan>&)
{
	// dudes interact with a high five and nothing more
	return NoEvents;
}

PhysicsEvents TheMan::touch(const shared_ptr<Ghost>& ghost_ptr)
{
	return Physics::ghost_man_interaction(ghost_ptr, shared_from_this());
}

bool TheMan::get_promoted() const
{
	return m_promoted;
}
