#include "control/Event.h"
#include "control/MoveConstants.h"

Event::Event(const Event::Type&   type,
             const ObjectPtr&     object,
             const Coordinate&    coord_x,
             const Coordinate&    coord_y,
             const MoveDirection& dir,
             const Block&         block)
	: m_type                  (type)
	, m_object_argument       (object)
	, m_coordinate_argument_x (coord_x)
	, m_coordinate_argument_y (coord_y)
	, m_direction_argument    (dir)
	, m_block_argument        (block)
{}


Event event_move(MoveDirection dir, ObjectPtr obj)
{
	return Event(Event::Type::Move, obj, // non-standart
	             StandartX, StandartY,   // standart
	             dir,                    // non-standart
	             StandartBlock);         // standart
}
Event event_kill(ObjectPtr obj)
{
	return Event(Event::Type::Kill, obj, // only non-standart
	             StandartX, StandartY, StandartDirection, StandartBlock);
}
Event event_promote(ObjectPtr obj)
{
	return Event(Event::Type::Promote, obj, // only non-standart
	             StandartX, StandartY, StandartDirection, StandartBlock);
}
Event event_demote(ObjectPtr obj)
{
	return Event(Event::Type::Demote, obj, // only non-standart
	             StandartX, StandartY, StandartDirection, StandartBlock);
}
Event event_eat_point(Coordinate x, Coordinate y)
{
	return Event(Event::Type::EatPoint,             // non-standart
	             ObjectPtr(nullptr),                // standarty
	             x, y,                              // non-standart
	             StandartDirection, StandartBlock); // standart
}
Event event_destroy_wall(Coordinate x, Coordinate y)
{
	return Event(Event::Type::DestroyWall,          // non-standart
	             ObjectPtr(nullptr),                // standarty
	             x, y,                              // non-standart
	             StandartDirection, StandartBlock); // standart
}
Event event_add_wall(Coordinate x, Coordinate y, Block block)
{
	return Event(Event::Type::AddWall, // non-standart
	             ObjectPtr(nullptr),   // standarty
	             x, y,                 // non-standart
	             StandartDirection,    // standart
	             block);               // non-standart
}
Event event_nothing()
{
	return Event(Event::Type::Nothing, ObjectPtr(nullptr),
	             StandartX, StandartY, StandartDirection, StandartBlock);
}

Event::Type   Event::get_type()                  const
{
	return m_type;
}
ObjectPtr     Event::get_object_argument()       const
{
	return m_object_argument;
}
Coordinate    Event::get_coordinate_argument_x() const
{
	return m_coordinate_argument_x;
}
Coordinate    Event::get_coordinate_argument_y() const
{
	return m_coordinate_argument_y;
}
Block         Event::get_block_argument()        const
{
	return m_block_argument;
}
MoveDirection Event::get_direction_argument()    const
{
	return m_direction_argument;
}
