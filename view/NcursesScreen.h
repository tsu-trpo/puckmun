#pragma once

// exception-safe инициализация экрана ncurses, не позволяющая существовать
// более чем одной штуке

#include <ncurses.h>

class NcursesScreen
{
	static size_t m_screens_open;

	// tells whether we're an rhs in the move constructor
	bool m_is_transferred;
public:
	NcursesScreen();
	NcursesScreen(NcursesScreen&&);
	NcursesScreen(const NcursesScreen&) = delete;
	~NcursesScreen();
};

// vim: tw=78
