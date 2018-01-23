#include "inputs/commands/TheManSetCurrent.h"

#include "errors/ErrorConstants.h"
#include "objects/TheMan.h"

TheManSetCurrent::TheManSetCurrent(MoveDirection dir)
	: m_to_set (dir)
{}


unique_ptr<BaseCommand> TheManSetCurrent::clone() const
{
	return unique_ptr<BaseCommand>( new TheManSetCurrent(*this) );
}


void TheManSetCurrent::update(const shared_ptr<AnimateObject>& pre_object_ptr)
{
	// plan setting methods are unique for different objects because objects
	// themselves are very different, so pointer cast is the only way
	auto object_ptr =
		std::dynamic_pointer_cast<TheMan, AnimateObject>(pre_object_ptr);

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

// vim: tw=78
