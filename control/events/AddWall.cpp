#include "control/events/AddWall.h"

Events::AddWall::AddWall(Coordinate x, Coordinate y, Block block)
	: m_x     (x)
	, m_y     (y)
	, m_block (block)
{
}

void Events::AddWall::execute_physics(GameField& field) const
{
	field.map.change_block(m_x, m_y, m_block);
}

void Events::AddWall::execute_graphics(const GameField& field,
                                       Render& render) const
{
	render.redraw_any_block(field, m_block, m_x, m_y);
}

bool Events::AddWall::graphics_first() const
{
	return false;
}

// vim: tw=78
