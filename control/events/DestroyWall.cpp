#include "control/events/DestroyWall.h"

Events::DestroyWall::DestroyWall(Coordinate x, Coordinate y, Block block)
	: m_x     (x)
	, m_y     (y)
{
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
