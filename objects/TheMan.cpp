#include "objects/TheMan.h"

#include "objects/GameObject.h"
#include "objects/Ghost.h"
#include "control/Physics.h"

const PhysicsEvents NoEvents =
	PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

TheMan::TheMan()
	: m_promoted (false)
	, m_bg_color (Color::Yellow)
	, m_fg_color (Color::Yellow)
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
	if (m_promoted)
	{
		// whoah, cool dude eats him
		// but first, cast away constness
		auto to_eat = const_pointer_cast<Ghost>(ghost_ptr);
		auto event = Events::make_demote(to_eat);
		return PhysicsEvents { std::list<Event>{event}, {} };
	}
	else
	{
		// dude dies, sad sad sad
		return { {Events::make_die_hero()}, {} };
	}
}

bool TheMan::get_promoted() const
{
	return m_promoted;
}
