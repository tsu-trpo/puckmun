#pragma once

#include "objects/ViewableObject.h"
#include "objects/GameField.h"

class Render
{
public:
	Render& redraw_object_nomove(const GameField&, const ViewableObject&);

	Render& redraw_object_pre_move(const GameField&, const ViewableObject&,
	                               const Coordinate&, const Coordinate&);

	Render& redraw_object_post_move(const GameField&,
	                                const Coordinate&, const Coordinate&,
	                                const ViewableObject&);

	Render& redraw_map_block(const GameField&,
	                          const Coordinate&, const Coordinate&);

	Render& redraw_any_block(const GameField&, const Block&,
	                         const Coordinate&, const Coordinate&);

	Render& redraw_complete(const GameField&);
};

// vim: tw=78
