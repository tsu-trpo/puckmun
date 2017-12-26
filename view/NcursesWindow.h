#pragma once

#include <ncurses.h>

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
	WINDOW* m_window;

	// tells whether we were once an rhs in the move constructor
	bool m_is_transferred;

public:
	// topleft corner coords, height, width, border style
	NcursesWindow(int x, int y, int h, int w, const Border&);
	NcursesWindow(const NcursesWindow&) = delete;
	NcursesWindow(NcursesWindow&&);
	~NcursesWindow();

	NcursesWindow& rebox();

	WINDOW* get() const;
};
