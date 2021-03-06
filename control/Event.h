#pragma once

// defines event: an object which holds what changed
// events are generated by physics && are passed to graphics && are applied

#include <memory>

#include "objects/GameField.h"
#include "view/GameRender.h"
#include "control/GameStatus.h"
#include "control/events/BaseEvent.h"

using std::unique_ptr;

class Event
{
	std::unique_ptr<BaseEvent> m_event;

public:
	Event(unique_ptr<BaseEvent>);
	Event(const Event&);

	// non-const reference because other ways are too hard. What have I become
	GameStatus execute_physics(GameField&) const;
	void execute_graphics(const GameField&, GameRender&) const;

	// tells whether the event wants graphics to be executed before physics
	bool graphics_first() const;
};

namespace Events
{
	// см control/events/README.md за описанием каждого ивента
	Event make_add_wall(Coordinate x, Coordinate y, Block block);
	Event make_demote(const shared_ptr<GameObject>& object);
	Event make_destroy_wall(Coordinate x, Coordinate y);
	Event make_eat_point(Coordinate x, Coordinate y);
	Event make_move(const shared_ptr<GameObject>& obj, MoveDirection dir);
	Event make_nothing();
	Event make_promote(const shared_ptr<GameObject>& object);
	Event make_die_hero();
}

// vim: tw=78
