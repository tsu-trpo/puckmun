#include "view/NcursesScreen.h"

#include "errors/GameRender-errors.h"
#include "errors/NcursesError.cpp"

size_t NcursesScreen::m_screens_open = 0;

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

NcursesScreen& NcursesScreen::register_color_pair(Color fore, Color back)
{
	NcursesScreen::MapKey key {fore, back};
	auto search = m_registered_colors.find(key);

	//if pair is not registered
	if (search == m_registered_colors.end())
	{
		//register in ncurses
		CALL init_pair(m_next_pair_number,
		         ncurses_color(fore), ncurses_color(back)) RAISE;

		//remember its number
		m_registered_colors[key] = m_next_pair_number;
		m_next_pair_number += 1;
	}
	//allows reregistering
	return *this;
}

chtype NcursesScreen::color_pair(Color fore, Color back)
{
	NcursesScreen::MapKey key {fore, back};
	// throws some map exception if pair does not exist
	return COLOR_PAIR(m_registered_colors.at(key));
}
