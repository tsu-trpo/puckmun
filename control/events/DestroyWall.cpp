#include "control/events/DestroyWall.h"

Events::DestroyWall::DestroyWall(Coordinate x, Coordinate y)
	: m_x     (x)
	, m_y     (y)
{
}

std::unique_ptr<BaseEvent> Events::DestroyWall::clone() const
{
	return unique_ptr<BaseEvent>( new DestroyWall(*this) );
}

void Events::DestroyWall::execute_physics(GameField& field) const
{
	field.map.change_block(m_x, m_y, Block::Space);
}

void Events::DestroyWall::execute_graphics(const GameField& field,
                                       Render& render) const
{
	render.redraw_any_block(field, Block::Space, m_x, m_y);
}

bool Events::DestroyWall::graphics_first() const
{
	return false;
}

// vim: tw=78
