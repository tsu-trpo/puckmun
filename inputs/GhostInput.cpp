#include "inputs/GhostInput.h"

#include "control/MoveDirection.h"

Command GhostInput::plan(const GameField& field,
                         const shared_ptr<const AnimateObject>& pre_object_ptr)
{
	auto object_ptr =
		std::dynamic_pointer_cast<const Ghost, const AnimateObject>
			(pre_object_ptr);

	shared_ptr<const GameObject> target;
	for (auto obj : field.objects)
	{
		if (obj->eats_points())
		{
			target = obj;
			break;
		}
	}

	if (target->get_y() > object_ptr->get_y())
	{
		return Commands::make_ghost_set_current(MoveDirection::Down);
	}
	if (target->get_y() < object_ptr->get_y())
	{
		return Commands::make_ghost_set_current(MoveDirection::Up);
	}
	if (target->get_x() > object_ptr->get_x())
	{
		return Commands::make_ghost_set_current(MoveDirection::Right);
	}
	if (target->get_x() < object_ptr->get_x())
	{
		return Commands::make_ghost_set_current(MoveDirection::Left);
	}

	return Commands::make_no_command();
}

// vim: tw=78
