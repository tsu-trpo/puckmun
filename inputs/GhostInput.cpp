#include "inputs/GhostInput.h"

#include "control/MoveDirection.h"

Command GhostInput::plan(const GameField&,
                         const shared_ptr<const AnimateObject>& pre_object_ptr)
{
	auto object_ptr =
		std::dynamic_pointer_cast<const Ghost, const AnimateObject>
			(pre_object_ptr);

	if (object_ptr->get_current() == MoveDirection::Left)
	{
		return Commands::make_ghost_set_current(MoveDirection::Right);
	}
	else
	{
		return Commands::make_ghost_set_current(MoveDirection::Left);
	}
}

// vim: tw=78
