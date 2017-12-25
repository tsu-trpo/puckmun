#include "view/NcursesScreen.h"

#include "errors/GameRender-errors.h"
#include "errors/NcursesError.h"

size_t NcursesScreen::m_screens_open = 0;

size_t NcursesScreen::get_screens_open()
{
	return m_screens_open;
}

NcursesScreen::NcursesScreen()
	: m_is_transferred (false)
	, m_registered_colors {}
	, m_next_pair_number (1)
{
	if (m_screens_open > 0)
	{
		throw ScreenError("NcursesScreen: too many screens created");
	}
	m_screens_open += 1;

	initscr();
}

NcursesScreen::NcursesScreen(NcursesScreen&& other)
	: m_is_transferred (false)
	, m_registered_colors (std::move(other.m_registered_colors))
	, m_next_pair_number (other.m_next_pair_number)
{
	other.m_is_transferred = true;
	// screen is initialized, control of screen is transferred
	// nothing to do
}

NcursesScreen::~NcursesScreen()
{
	if (m_is_transferred) return;

	endwin();
	m_screens_open -= 1;
}

void NcursesScreen::register_color_pair(const NcursesScreen::MapKey& key)
{
	auto search = m_registered_colors.find(key);

	//if pair is not registered
	if (search == m_registered_colors.end())
	{
		//register in ncurses
		CALL init_pair(m_next_pair_number,
		               ncurses_color(key.foreground),
		               ncurses_color(key.background)) RAISE;

		//remember its number
		m_registered_colors[key] = m_next_pair_number;
		m_next_pair_number += 1;
	}
	//allows reregistering
}

chtype NcursesScreen::color_pair(Color fore, Color back)
{
	NcursesScreen::MapKey key {fore, back};

	// register or re-register the pair
	this->register_color_pair(key);

	// return the registered pair
	return COLOR_PAIR(m_registered_colors.at(key));
}
