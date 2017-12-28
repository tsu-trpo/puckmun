#include "control/Physics.h"

using std::make_pair;

const PhysicsEvents NoEvents = PhysicsEvents{ list<Event> {}, list<ScheduledEvent> {} };

namespace Physics
{
	PhysicsEvents move_object(const GameField& field, ObjectPtrArg object,
	                          const MoveDirection& direction)
	{
		Coordinate next_x = object->get_x();
		Coordinate next_y = object->get_y();

		list<Event> imm_events;
		list<ScheduledEvent> plan_events;

		Coordinate map_left_border  = 0;
		Coordinate map_right_border = field.map.get_width() - 1;
		Coordinate map_upper_border = 0;
		Coordinate map_lower_border = field.map.get_height() - 1;

		switch (direction)
		{
			case MoveDirection::Up:
				if (next_y == map_upper_border) return NoEvents;
				next_y -= 1;
				break;
			case MoveDirection::Down:
				if (next_y == map_lower_border) return NoEvents;
				next_y += 1;
				break;
			case MoveDirection::Left:
				if (next_x == map_left_border)  return NoEvents;
				next_x -= 1;
				break;
			case MoveDirection::Right:
				if (next_x == map_right_border) return NoEvents;
				next_x += 1;
				break;
		}

		// don't move into a wall
		if (field.map.at(next_x, next_y) == Block::Wall)
		{
			return NoEvents;
		}

		// write the move event
		imm_events.push_back(Events::make_move(object, direction));

		// eat the small point
		if (field.map.at(next_x, next_y) == Block::Point
		    && object->eats_points())
		{
			imm_events.push_back(Events::make_eat_point(next_x, next_y));
		}

		// eat the big point
		if (field.map.at(next_x, next_y) == Block::BigPoint
		    && object->eats_points())
		{
			imm_events.push_back(Events::make_eat_point(next_x, next_y));
			imm_events.push_back(Events::make_promote(object));
		}

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

		return PhysicsEvents { imm_events, plan_events };
	}

	//dummy function for now
	PhysicsEvents interact_objects(ObjectPtrArg fst, ObjectPtrArg snd)
	{
		return fst->touch(snd);
	}
}
