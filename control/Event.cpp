#include "control/Event.h"

#include "control/events/AddWall.h"
#include "control/events/Demote.h"
#include "control/events/DestroyWall.h"
#include "control/events/EatPoint.h"
#include "control/events/Move.h"
#include "control/events/Nothing.h"
#include "control/events/Promote.h"
#include "control/events/DieHero.h"

Event::Event(unique_ptr<BaseEvent> event)
	: m_event (std::move(event))
{
}

Event::Event(const Event& other)
	: m_event (other.m_event->clone())
{
}

GameStatus Event::execute_physics(GameField& field) const
{
	return m_event->execute_physics(field);
}

void Event::execute_graphics(const GameField& field, GameRender& render) const
{
	m_event->execute_graphics(field, render);
}

bool Event::graphics_first() const
{
	return m_event->graphics_first();
}

namespace Events
{
	Event make_add_wall(Coordinate x, Coordinate y, Block block)
	{
		return Event( unique_ptr<Events::AddWall>(
		                 new Events::AddWall(x, y, block))
		            );
	}

	Event make_demote(const shared_ptr<GameObject>& object)
	{
		return Event( unique_ptr<Events::Demote>(
		                 new Events::Demote(object))
		            );
	}

	Event make_destroy_wall(Coordinate x, Coordinate y)
	{
		return Event( unique_ptr<Events::DestroyWall>(
		                 new Events::DestroyWall(x, y))
		            );
	}

	Event make_eat_point(Coordinate x, Coordinate y)
	{
		return Event( unique_ptr<Events::EatPoint>(
		                 new Events::EatPoint(x, y))
		            );
	}

	Event make_move(const shared_ptr<GameObject>& obj, MoveDirection dir)
	{
		return Event( unique_ptr<Events::Move>(
		                 new Events::Move(obj, dir))
		            );
	}

	Event make_nothing()
	{
		return Event( unique_ptr<Nothing>(
		                 new Nothing)
					);
	}

	Event make_promote(const shared_ptr<GameObject>& object)
	{
		return Event( unique_ptr<Events::Promote>(
		                 new Events::Promote(object))
		            );
	}

	Event make_die_hero()
	{
		return Event( unique_ptr<DieHero>(
		                 new DieHero)
					);
	}
}

// vim: tw=78
