#include "view/NcursesScreen.h"

#include "errors/GameRender-errors.h"

size_t NcursesScreen::m_screens_open = 0;

NcursesScreen::NcursesScreen()
	: m_is_transferred (false)
{
	if (m_screens_open > 0)
	{
		throw ScreenError("Too many screens created in GameRenderer");
	}
	m_screens_open += 1;

	initscr();
}

NcursesScreen::NcursesScreen(NcursesScreen&& other)
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
