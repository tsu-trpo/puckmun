#pragma once

// Класс для рисования вещей во время игры. Содержит примитивные и не очень
// методы, дёргаемые ивентами

#include <ncurses.h>

#include "objects/ViewableObject.h"
#include "objects/GameField.h"
#include "objects/Block.h"

class GameRender
{
	static size_t m_screens_open;

	size_t m_max_x, m_max_y;
public:
	GameRender();
	~GameRender();
	// draw object at its place
	GameRender& redraw_object_nomove(const GameField&, const ViewableObject&);

	// draw objects with new coordinated provided
	GameRender& redraw_object_pre_move(const GameField&, const ViewableObject&,
	                               const Coordinate&, const Coordinate&);

	// draw objects with old coordinated provided
	GameRender& redraw_object_post_move(const GameField&,
	                                const Coordinate&, const Coordinate&,
	                                const ViewableObject&);

	GameRender& redraw_map_block(const GameField&,
	                          const Coordinate&, const Coordinate&);

	GameRender& redraw_any_block(const GameField&, const Block&,
	                         const Coordinate&, const Coordinate&);

	GameRender& redraw_complete(const GameField&);
};

// vim: tw=78
