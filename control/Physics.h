#pragma once

#include <list>
#include <map>

#include "control/Event.h"
#include "objects/GameField.h"
#include "objects/GameObject.h"
#include "control/MoveDirection.h"
#include "control/MoveConstants.h"

using std::list;
using ObjectPtrArg = const std::shared_ptr<GameObject>&;

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
	PhysicsEvents move_object(const GameField&, ObjectPtrArg,
	                          const MoveDirection&
	                         );

	PhysicsEvents interact_objects(ObjectPtrArg, ObjectPtrArg);
}

// vim: tw=78
