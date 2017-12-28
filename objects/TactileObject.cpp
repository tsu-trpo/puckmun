#include "objects/TactileObject.h"

#include "control/Event.h"

Event TactileObject::touch(shared_ptr<const TactileObject> other) const
{
	return other->touch(shared_from_this());
}


Event TactileObject::touch(shared_ptr<const TheMan>) const
{
	return Events::make_nothing();
}


Event TactileObject::touch(shared_ptr<const Ghost>) const
{
	return Events::make_nothing();
}

TactileObject::~TactileObject()
{
}
