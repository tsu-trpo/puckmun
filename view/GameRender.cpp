#include "view/GameRender.h"

#include "errors/GameRender-errors.h"
#include "view/BlockView.cpp"

#include "errors/NcursesError.h"

using std::to_string;

void log_wait(const string& msg)
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

const NcursesWindow::Border map_border {'|', '|', 'U', 'U', 'P', 'C', 'M', 'N'};

GameRender::GameRender(const Map& map)
	: m_screen ()
	, m_map_window (0, 1, map.get_width() + 2, map.get_height() + 2, map_border)
	, m_current_map_width (map.get_width())
	, m_current_map_height (map.get_height())
{
	if (!has_colors())
	{
		throw ScreenError("You terminal doesn't support colors");
	}

	CALL noecho() RAISE;

	CALL start_color() RAISE;

	CALL getmaxyx(stdscr, m_max_screen_y, m_max_screen_x) RAISE;

	//rebox after turning on colors
	m_map_window.rebox();
}

void GameRender::basic_draw(char body, Color fore, Color back)
{
	//turn on this color
	CALL wattron(m_map_window.get(), m_screen.color_pair(fore, back)) RAISE;
	//print the char
	CALL wechochar(m_map_window.get(), body) RAISE;
	//turn off that color
	CALL wattroff(m_map_window.get(), m_screen.color_pair(fore, back)) RAISE;
}

void GameRender::draw_current_block(const Block& block)
{
	//get how block looks
	Color fore, back; char body;
	std::tie(fore, back, body) = block_view(block);

	this->basic_draw(body, fore, back);
}

void GameRender::draw_current_object(const ViewableObject& object)
{
	auto fore = object.get_body_color();
	auto back = object.get_bg_color();
	auto body = object.get_form();

	this->basic_draw(body, fore, back);
}

GameRender& GameRender::redraw_complete(const GameField& field)
{
	bool too_wide = field.map.get_width() > m_current_map_width;
	bool too_high = field.map.get_height() > m_current_map_height;
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
			auto block = field.map.at(x, y);
			this->draw_current_block(block);
		}
	}

	// print all objects
	for (auto& object_ptr : field.objects)
	{
		this->map_cursor(object_ptr->get_x(), object_ptr->get_y());
		this->draw_current_object(*object_ptr);
	}

	//move cursor to idle position
	this->idle_cursor();

	return *this;
}

GameRender& GameRender::redraw_object_nomove(const GameField&,
                                             const ViewableObject& object)
{
	//move cursor to object position
	this->map_cursor(object.get_x(), object.get_y());
	//draw it
	this->draw_current_object(object);

	//move cursor to idle position
	this->idle_cursor();

	return *this;
}

GameRender& GameRender::redraw_object_pre_move(const GameField& field,
                                               const ViewableObject& object,
                                               Coordinate x, Coordinate y)
{
	//move cursor to object future position
	this->map_cursor(x, y);
	//draw it
	this->draw_current_object(object);

	//move to object past position
	this->map_cursor(object.get_x(), object.get_y());
	//redraw the block there
	auto block = field.map.at(object.get_x(), object.get_y());
	this->draw_current_block(block);

	//move cursor to idle position
	this->idle_cursor();

	return *this;
}

GameRender& GameRender::redraw_object_post_move(const GameField& field,
                                                Coordinate x, Coordinate y,
                                                const ViewableObject& object)
{
	//move cursor to object future position
	this->map_cursor(object.get_x(), object.get_y());
	//draw it
	this->draw_current_object(object);

	//move to object past position
	this->map_cursor(x, y);
	//redraw the block there
	auto block = field.map.at(x, y);
	this->draw_current_block(block);

	//move cursor to idle position
	this->idle_cursor();

	return *this;
}

GameRender& GameRender::redraw_map_block(const GameField& field,
                                         Coordinate x, Coordinate y)
{
	//move to block position
	this->map_cursor(x, y);
	//redraw
	auto block = field.map.at(x, y);
	this->draw_current_block(block);

	//move cursor to idle position
	this->idle_cursor();

	return *this;
}

GameRender& GameRender::redraw_any_block(const GameField&, const Block& block,
                                         Coordinate x, Coordinate y)
{
	//move to block position
	this->map_cursor(x, y);
	//redraw
	this->draw_current_block(block);

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
	if (x >= m_current_map_width || y >= m_current_map_height)
	{
		throw BadPosition(ERR_HEADER "moving cursor past map boundaries");
	}
	if (!m_map_window.get())
	{
		throw std::runtime_error(ERR_HEADER "window pointer is null");
	}
	CALL ::wmove(m_map_window.get(), y+1, x+1) RAISE;
}

// vim: tw=78
