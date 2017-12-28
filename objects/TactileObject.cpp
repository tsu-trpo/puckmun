#include "objects/TactileObject.h"

#include "control/Event.h"
#include "control/Physics.h"

const PhysicsEvents NoEvents =
	PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

PhysicsEvents TactileObject::touch(const shared_ptr<TactileObject>&)
{
	return NoEvents;
}


PhysicsEvents TactileObject::touch(const shared_ptr<TheMan>&)
{
	return NoEvents;
}


PhysicsEvents TactileObject::touch(const shared_ptr<Ghost>&)
{
	return NoEvents;
}

TactileObject::~TactileObject()
{
}
