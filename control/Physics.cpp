#include "control/Physics.h"

using std::make_pair;

#define NO_EVENTS PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} }

namespace Physics
{
	PhysicsEvents move_object(const GameField& field, ObjectPtrArg object,
	                          const MoveDirection& direction
	                         )
	{
		Coordinate next_x = object->get_x();
		Coordinate next_y = object->get_y();

		list<Event> imm_events;
		list<ScheduledEvent> plan_events;

		switch (direction)
		{
			case MoveDirection::Up:
				if (next_y == 0) return NO_EVENTS;
				next_y -= 1;
				break;
			case MoveDirection::Down:
				if (next_y == field.map.get_height() - 1) return NO_EVENTS;
				next_y -= 1;
				break;
			case MoveDirection::Left:
				if (next_x == 0) return NO_EVENTS;
				next_x -= 1;
				break;
			case MoveDirection::Right:
				if (next_x == field.map.get_width() - 1) return NO_EVENTS;
				next_x -= 1;
				break;
		}

		// write the move event
		imm_events.push_back(Events::move(object, direction));

		// interact with objects moved to
		for (auto& other_obj : field.objects)
		{
			if (other_obj->get_x() == next_x && other_obj->get_y() == next_y)
			{
				auto additional = interact_objects(object, other_obj);
				// add events to current
				imm_events.splice(imm_events.end(), additional.immediate);
				plan_events.splice(plan_events.end(), additional.delayed);
			}
		}
	}

	//dummy function for now
	PhysicsEvents interact_objects(ObjectPtrArg, ObjectPtrArg&)
	{
		PhysicsEvents r = { {}, {} };
		return r;
	}
}
