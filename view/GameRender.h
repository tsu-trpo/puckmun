#pragma once

// Класс для рисования вещей во время игры. Содержит примитивные и не очень
// методы, дёргаемые ивентами

#include <ncurses.h>

#include "objects/ViewableObject.h"
#include "objects/GameField.h"
#include "objects/Block.h"
#include "view/NcursesScreen.h"
#include "view/NcursesWindow.h"

class GameRender
{
	NcursesScreen m_screen;
	NcursesWindow m_map_window;

	// screen sizes
	size_t m_max_screen_x, m_max_screen_y;
	// width and height of map given to constructor.
	const Coordinate m_current_map_width;
	const Coordinate m_current_map_height;


	//move cursor to nowhere
	void idle_cursor();
	//move cursor to map line
	void map_cursor(Coordinate x, Coordinate y);
	//draw character under cursor
	void basic_draw(char, Color fore, Color back);
	//redraw block under cursor
	void draw_current_block(const Block&);
	//redraw object under cursor
	void draw_current_object(const ViewableObject&);
	//redraw first found object at coordinates, except for the one specified
	//for exclude. Выглядит как хак, но это потому что ViewableObject-y нельзя
	//придумать какое-то значимое сравнение == на совпадение экземпляров.
	//которое бы тоже не опиралось на указатели
	void find_redraw_object(const GameField&, Coordinate, Coordinate,
	                        const ViewableObject* const exclude);

public:
	GameRender(const Map&);
	GameRender(const GameRender&) = delete;
	GameRender(GameRender&&) = default;

	// draw object at its place
	GameRender& redraw_object_nomove(const GameField&, const ViewableObject&);

	// draw objects with new coordinated provided
	GameRender& redraw_object_pre_move(const GameField&, const ViewableObject&,
	                                   Coordinate x, Coordinate y);

	// draw objects with old coordinated provided
	GameRender& redraw_object_post_move(const GameField&,
	                                    Coordinate x, Coordinate y,
	                                    const ViewableObject&);

	GameRender& redraw_map_block(const GameField&,
	                          Coordinate x, Coordinate y);

	GameRender& redraw_any_block(const GameField&, const Block&,
	                         Coordinate x, Coordinate y);

	GameRender& redraw_complete(const GameField&);

	// print a line to statusline
	GameRender& print_status(const string&);
};

// vim: tw=78
