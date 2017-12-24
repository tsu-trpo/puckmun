#include "view/GameRender.h"

#include "errors/GameRender-errors.h"
#include "view/BlockView.cpp"

GameRender::GameRender()
	: m_screen()
{
	if (!has_colors())
	{
		throw ScreenError("You terminal doesn't support colors");
	}

	noecho();

	start_color();
	init_color_pairs();

	getmaxyx(stdscr, m_max_y, m_max_x);
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
			init_pair( fore * COLORS + back, fore, back );
		}
	}
}

chtype GameRender::get_color_pair(Color fore, Color back)
{
	return COLOR_PAIR( ncurses_color(fore) * COLORS + ncurses_color(back) );
}

void log(const string& msg)
{
	mvprintw(0, 0, "%s", msg.c_str());
	refresh();
	getch();
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
			attron(get_color_pair(fore, back));
			wechochar(m_map_window, body);
			attroff(get_color_pair(fore, back));
		}
	}
	this->idle_cursor();

	return *this;
}

void GameRender::idle_cursor()
{
	::move(0, 0);
}

void GameRender::map_line_cursor(Coordinate y)
{
	// go to map screen's line number y
	::wmove(m_map_window, y+1, 0);
}

// vim: tw=78
