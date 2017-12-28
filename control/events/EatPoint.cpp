#include "control/events/EatPoint.h"
#include "objects/Block.h"

Events::EatPoint::EatPoint(Coordinate x, Coordinate y)
	: m_x (x)
	, m_y (y)
{
}

std::unique_ptr<BaseEvent> Events::EatPoint::clone() const
{
	return unique_ptr<BaseEvent>( new EatPoint(*this) );
}

GameStatus Events::EatPoint::execute_physics(GameField& field) const
{
	field.map.change_block(m_x, m_y, Block::Space);
	field.points_left -= 1;

	return GameStatus::Continue;
}

void Events::EatPoint::execute_graphics(const GameField&, GameRender&) const
{
	// this event happens only when the man is in the same cell as the point,
	// so there is no point in redrawing anything, as the point is unseen by
	// the man moving to the cell, and man is redrawn with the move event
	return;
}

bool Events::EatPoint::graphics_first() const
{
	return false;
}

// vim: tw=78
