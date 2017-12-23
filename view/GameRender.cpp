#include "view/GameRender.h"

#include "errors/GameRender-errors.h"

GameRender::GameRender()
{
	if (m_screens_open > 0)
	{
		throw ScreenOverflow("Too many screens created in GameRenderer");
	}

	initscr();
	noecho();
	start_color();
	getmaxyx(stdscr, m_max_y, m_max_x);
}

GameRender::~GameRender()
{
	endwin();
}

GameRender& GameRender::redraw_complete(const GameField& field)
{
	
}

// vim: tw=78
