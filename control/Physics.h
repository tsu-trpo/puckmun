#pragma once

#include <list>
#include <map>

#include "control/Event.h"
#include "objects/GameField.h"
#include "objects/GameObject.h"
#include "control/MoveDirection.h"
#include "control/MoveConstants.h"

using std::list;

struct ScheduledEvent
{
	Event event;
	TimeT time;
};
struct PhysicsEvents
{
	list<Event> immediate;
	list<ScheduledEvent> delayed;
};

namespace Physics
{
	PhysicsEvents move_object(const GameField&, const GameObject&,
	                          const MoveDirection&
	                         );

	PhysicsEvents interact_objects(const GameObject&, const GameObject&);
}

// vim: tw=78
