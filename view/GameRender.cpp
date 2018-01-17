#include "view/GameRender.h"

#include "errors/GameRender-errors.h"
#include "view/BlockView.cpp"

#include "errors/NcursesError.h"

using std::to_string;


// border that reads puckmun
const NcursesWindow::Border map_border {'|', '|', 'U', 'U', 'P', 'C', 'M', 'N'};
// where cursor goes after draw command
const int idle_pos_x = 0;
const int idle_pos_y = 0;
// status position
const int status_pos_x = 1;
const int status_pos_y = 0;
// map screen position: offset 1 from top for the status line and 1 left for
// the symmtry
const int map_pos_x = 1;
const int map_pos_y = 1;


GameRender& GameRender::print_status(const string& msg)
{
	CALL mvprintw(status_pos_y, status_pos_x, "%s", msg.c_str()) RAISE;
	CALL refresh() RAISE;
	this->idle_cursor();

	return *this;
}

GameRender::GameRender(const Map& map)
	: m_screen ()
	, m_map_window(map_pos_x, map_pos_y,
	               map.get_width() + 2, map.get_height() + 2,//+2 for the border
	               map_border)
	, m_current_map_width (map.get_width())
	, m_current_map_height (map.get_height())
{
	if (!has_colors())
	{
		throw ScreenError("You terminal doesn't support colors");
	}

	// disable keyboard characters being printed at all
	CALL noecho() RAISE;

	CALL start_color() RAISE;

	// get screen size
	CALL getmaxyx(stdscr, m_max_screen_y, m_max_screen_x) RAISE;

	bool too_wide = map.get_width()  + map_pos_x + 2 > m_max_screen_x;
	bool too_high = map.get_height() + map_pos_y + 2 > m_max_screen_y;
	if (too_wide || too_high)
	{
		throw BadMap("Could not create render: map size too big");
	}

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

void GameRender::find_redraw_object(const GameField& field,
                                    Coordinate x, Coordinate y,
                                    const ViewableObject* const exclude)
{
	for (auto& object_ptr : field.objects)
	{
		if (   object_ptr->get_x() == x
		    && object_ptr->get_y() == y
		    && exclude != object_ptr.get() )
		{
			this->map_cursor(x, y);
			draw_current_object(*object_ptr);
			return;
		}
	}
}

GameRender& GameRender::redraw_complete(const GameField& field)
{
	bool too_wide = field.map.get_width() > m_current_map_width;
	bool too_high = field.map.get_height() > m_current_map_height;
	if (too_wide || too_high)
	{
		throw BadMap("Could not draw map: size too big");
	}

	// print all blocks
	for (Coordinate y = 0; y < field.map.get_height(); ++y)
	{
		// position at new line
		this->map_cursor(0, y);
		for (Coordinate x = 0; x < field.map.get_width(); ++x)
		{
			auto block = field.map.at(x, y);
			this->draw_current_block(block);
			// this will move the cursor to the next block
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
	//redraw object there if it exists
	this->find_redraw_object(field, object.get_x(), object.get_y(), &object);

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
	//redraw object there if it exists
	this->find_redraw_object(field, x, y, nullptr);

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
	CALL ::move(idle_pos_y, idle_pos_x) RAISE;
}

void GameRender::map_cursor(Coordinate x, Coordinate y)
{
	// arguments should be in range 0..size
	if (x >= m_current_map_width || y >= m_current_map_height)
	{
		throw BadPosition(ERR_HEADER "moving cursor past map boundaries");
	}
	if (!m_map_window.get())
	{
		throw std::runtime_error(ERR_HEADER "window pointer is null");
	}
	// it seems like i can use window-relative position here
	// add 1 to account for border size
	CALL ::wmove(m_map_window.get(), y+1, x+1) RAISE;
}

// vim: tw=78
