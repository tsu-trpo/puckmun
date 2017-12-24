#include "view/GameRender.h"

#include "errors/GameRender-errors.h"
#include "view/BlockView.cpp"

#include "errors/NcursesError.h"

void log(const string& msg)
{
	CALL mvprintw(0, 0, "%s", msg.c_str()) RAISE;
	CALL refresh() RAISE;
	CALL getch() RAISE;
}

GameRender::GameRender()
	: m_screen()
{
	if (!has_colors())
	{
		throw ScreenError("You terminal doesn't support colors");
	}

	CALL noecho() RAISE;

	CALL start_color() RAISE;
	init_color_pairs();

	CALL getmaxyx(stdscr, m_max_y, m_max_x) RAISE;
	//for now
	m_max_map_width  = m_max_x;
	m_max_map_height = m_max_y;
	//as the returned amount is not max, but size
	m_max_x -= 1; m_max_y -= 1;

	//seems like it should be set after everything else
	m_map_window = stdscr;
}

void GameRender::init_color_pairs()
{
	for (short fore = 0; fore < COLORS; ++fore)
	{
		for (short back = 0; back < COLORS; ++back)
		{
			CALL init_pair( fore * COLORS + back, fore, back ) RAISE;
		}
	}
}

chtype GameRender::get_color_pair(Color fore, Color back)
{
	return COLOR_PAIR( ncurses_color(fore) * COLORS + ncurses_color(back) );
}

GameRender& GameRender::redraw_complete(const GameField& field)
{
	if (field.map.get_width() > m_max_map_width
	   || field.map.get_height() > m_max_map_height)
	{
		throw BadMap("Map size too big");
	}

	for (Coordinate y = 0; y < field.map.get_height(); ++y)
	{
		this->map_line_cursor(y);
		for (Coordinate x = 0; x < field.map.get_width(); ++x)
		{
			Color fore, back; char body;
			std::tie(fore, back, body) = block_view(field.map.at(x, y));

			if (m_map_window != stdscr)
			{
				throw std::runtime_error("fuuuuuuuuuuck");
			}
			CALL attron(get_color_pair(fore, back)) RAISE;
			CALL wechochar(m_map_window, body) RAISE;
			CALL attroff(get_color_pair(fore, back)) RAISE;
		}
	}
	this->idle_cursor();

	return *this;
}

void GameRender::idle_cursor()
{
	CALL ::move(0, 0) RAISE;
}

void GameRender::map_line_cursor(Coordinate y)
{
	// go to map screen's line number y
	CALL ::wmove(m_map_window, y+1, 0) RAISE;
}

// vim: tw=78
