#include "view/GameRender.h"

#include "errors/GameRender-errors.h"

GameRender::GameRender()
{
	if (m_screens_open > 0)
	{
		throw ScreenError("Too many screens created in GameRenderer");
	}
	if (!has_colors())
	{
		throw ScreenError("You terminal doesn't support colors");
	}

	initscr();
	noecho();

	start_color();
	init_color_pairs();

	getmaxyx(stdscr, m_max_y, m_max_x);
	//for now
	m_max_map_width  = m_max_x;
	m_max_map_height = m_max_y;
	//as the returned amount is not max, but size
	m_max_x -= 1; m_max_y -= 1;
}

GameRender::~GameRender()
{
	endwin();
}

void GameRender::init_color_pairs()
{
	for (short fore = 0; fore < COLORS; ++fore)
	{
		for (short back = 0; back < COLORS; ++back)
		{
			init_pair( fore * COLORS + back, fore, back );
		}
	}
}

chtype GameRender::get_color_pair(Color fore, Color back)
{
	return COLOR_PAIR( ncurses_color(fore) * COLORS + ncurses_color(back) );
}


GameRender& GameRender::redraw_complete(const GameField& field)
{
	
}

// vim: tw=78
