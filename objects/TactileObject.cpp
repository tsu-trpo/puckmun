#include "objects/TactileObject.h"

#include "control/Event.h"

Event TactileObject::touch(shared_ptr<const TactileObject>) const
{
	return Events::make_nothing();
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
