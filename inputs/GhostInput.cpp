#include "inputs/GhostInput.h"

#include "control/MoveDirection.h"

Command GhostInput::plan(const GameField&,
                         const shared_ptr<const AnimateObject>& pre_object_ptr)
{
	auto object_ptr =
		std::dynamic_pointer_cast<const Ghost, const AnimateObject>
			(pre_object_ptr);

	switch (object_ptr->get_current())
	{
		case MoveDirection::Up:
			return Commands::make_ghost_set_current(MoveDirection::Right);
		case MoveDirection::Right:
			return Commands::make_ghost_set_current(MoveDirection::Down);
		case MoveDirection::Down:
			return Commands::make_ghost_set_current(MoveDirection::Left);
		case MoveDirection::Left:
			return Commands::make_ghost_set_current(MoveDirection::Up);
	}

	return Commands::make_no_command();
}

// vim: tw=78
