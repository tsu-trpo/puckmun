#include "view/GameRender.h"

#include "errors/GameRender-errors.h"
#include "view/BlockView.cpp"

#include "errors/NcursesError.h"

using std::to_string;

void log(const string& msg)
{
	CALL mvprintw(0, 0, "%s", msg.c_str()) RAISE;
	CALL refresh() RAISE;
	CALL getch() RAISE;
}

void log_nowait(const string& msg)
{
	CALL mvprintw(0, 0, "%s", msg.c_str()) RAISE;
	CALL refresh() RAISE;
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

	CALL getmaxyx(stdscr, m_max_y, m_max_x) RAISE;
	//for now
	m_max_map_width  = m_max_x;
	m_max_map_height = m_max_y;
	//as the returned amount is not max, but size
	m_max_x -= 1; m_max_y -= 1;

	//seems like it should be set after everything else
	m_map_window = stdscr;
}

GameRender& GameRender::redraw_complete(const GameField& field)
{
	bool too_wide = field.map.get_width() > m_max_map_width;
	bool too_high = field.map.get_height() > m_max_map_height;
	if (too_wide || too_high)
	{
		throw BadMap("Map size too big");
	}

	// print all blocks
	for (Coordinate y = 0; y < field.map.get_height(); ++y)
	{
		this->map_cursor(0, y);
		for (Coordinate x = 0; x < field.map.get_width(); ++x)
		{
			//get how block looks
			Color fore, back; char body;
			std::tie(fore, back, body) = block_view(field.map.at(x, y));

			//register or re-register block's colors
			m_screen.register_color_pair(fore, back);
			//turn on this color
			CALL wattron(m_map_window, m_screen.color_pair(fore, back)) RAISE;
			//print the char
			CALL wechochar(m_map_window, body) RAISE;
			//turn off that color
			CALL wattroff(m_map_window, m_screen.color_pair(fore, back)) RAISE;
		}
	}

	for (auto& object_ptr : field.objects)
	{
		this->map_cursor(object_ptr->get_x(), object_ptr->get_y());

		auto fore = object_ptr->get_body_color();
		auto back = object_ptr->get_bg_color();
		auto body = object_ptr->get_form();

		//register or re-register block's colors
		m_screen.register_color_pair(fore, back);
		//turn on this color
		CALL wattron(m_map_window, m_screen.color_pair(fore, back)) RAISE;
		//print the char
		CALL wechochar(m_map_window, body) RAISE;
		//turn off that color
		CALL wattroff(m_map_window, m_screen.color_pair(fore, back)) RAISE;
	}

	//move cursor to idle position
	this->idle_cursor();

	return *this;
}

void GameRender::idle_cursor()
{
	CALL ::move(0, 0) RAISE;
}

void GameRender::map_cursor(Coordinate x, Coordinate y)
{
	CALL ::wmove(m_map_window, y+1, x) RAISE;
}

// vim: tw=78
