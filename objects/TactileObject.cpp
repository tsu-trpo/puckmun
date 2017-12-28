#include "objects/TactileObject.h"

#include "control/Event.h"
#include "control/Physics.h"

const PhysicsEvents NoEvents =
	PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

PhysicsEvents TactileObject::touch(shared_ptr<const TactileObject>) const
{
	return NoEvents;
}


PhysicsEvents TactileObject::touch(shared_ptr<const TheMan>) const
{
	return NoEvents;
}


PhysicsEvents TactileObject::touch(shared_ptr<const Ghost>) const
{
	return NoEvents;
}

TactileObject::~TactileObject()
{
}
