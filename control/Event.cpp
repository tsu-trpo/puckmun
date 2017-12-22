#include "control/Event.h"

#include "control/events/AddWall.h"
#include "control/events/Demote.h"
#include "control/events/DestroyWall.h"
#include "control/events/EatPoint.h"
#include "control/events/Move.h"
#include "control/events/Nothing.h"
#include "control/events/Promote.h"

Event::Event(unique_ptr<BaseEvent> event)
	: m_event (std::move(event))
{
}

Event::Event(const Event& other)
	: m_event (other.m_event->clone())
{
}

void Event::execute_physics(GameField& field) const
{
	m_event->execute_physics(field);
}

void Event::execute_graphics(const GameField& field, Render& render) const
{
	m_event->execute_graphics(field, render);
}

bool Event::graphics_first() const
{
	return m_event->graphics_first();
}

namespace Events
{
	Event add_wall(Coordinate x, Coordinate y, Block block)
	{
		return Event( unique_ptr<Events::AddWall>(
		                 new Events::AddWall(x, y, block))
		            );
	}

	Event demote(const shared_ptr<GameObject>& object)
	{
		return Event( unique_ptr<Events::Demote>(
		                 new Events::Demote(object))
		            );
	}

	Event destroy_wall(Coordinate x, Coordinate y)
	{
		return Event( unique_ptr<Events::DestroyWall>(
		                 new Events::DestroyWall(x, y))
		            );
	}

	Event eat_point(Coordinate x, Coordinate y)
	{
		return Event( unique_ptr<Events::EatPoint>(
		                 new Events::EatPoint(x, y))
		            );
	}

	Event move(const shared_ptr<GameObject>& obj, MoveDirection dir)
	{
		return Event( unique_ptr<Events::Move>(
		                 new Events::Move(obj, dir))
		            );
	}

	Event nothing()
	{
		return Event( unique_ptr<Nothing>(
		                 new Nothing)
					);
	}

	Event promote(const shared_ptr<GameObject>& object)
	{
		return Event( unique_ptr<Events::Promote>(
		                 new Events::Promote(object))
		            );
	}
}
//AddWall.cpp
//Demote.cpp
//DestroyWall.cpp
//EatPoint.cpp
//Move.cpp
//Nothing.cpp
//Promote.cpp
