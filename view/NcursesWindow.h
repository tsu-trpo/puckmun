#pragma once

#include <ncurses.h>

#include "view/NcursesScreen.h"

class NcursesWindow
{
public:
	struct Border
	{
		chtype left, right, top, bottom;
		chtype topleft, topright;
		chtype botleft, botright;
	};

private:
	// border symbols
	Border m_border;
	// ncurses window pointer
	WINDOW* m_window = nullptr;

	// tells whether we were once an rhs in the move constructor
	// потому что если однажды окно передали, то уже нет гарантии, что с ним
	// можно обращаться
	bool m_is_transferred = false;

	// as it is neccesary for there to be a screen for a window, we keep our
	// personal screen
	NcursesScreen m_personal_screen;

public:
	// topleft corner coords, width, height, border style
	NcursesWindow(int x, int y, int w, int h, const Border&);
	NcursesWindow(const NcursesWindow&) = delete;
	NcursesWindow(NcursesWindow&&);
	~NcursesWindow();

	// redraw the box in the window
	NcursesWindow& rebox();

	WINDOW* get() const;
};

// vim: tw=78
