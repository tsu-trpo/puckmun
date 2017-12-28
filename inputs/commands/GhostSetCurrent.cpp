#include "inputs/commands/GhostSetCurrent.h"

#include "errors/ErrorConstants.h"
#include "objects/Ghost.h"

GhostSetCurrent::GhostSetCurrent(MoveDirection dir)
	: m_to_set (dir)
{}


unique_ptr<BaseCommand> GhostSetCurrent::clone() const
{
	return unique_ptr<BaseCommand>( new GhostSetCurrent(*this) );
}


void GhostSetCurrent::update(const shared_ptr<AnimateObject>& pre_object_ptr)
{
	// plan setting methods are unique for different objects because objects
	// themselves are very different, so pointer cast is the only way
	auto object_ptr =
		std::dynamic_pointer_cast<Ghost, AnimateObject>(pre_object_ptr);

	if (object_ptr)
	{
		object_ptr->set_current(m_to_set);
	}
	else
	{
		throw std::logic_error(ERR_HEADER
			"possibly passed an incorrect object type");
	}
}
