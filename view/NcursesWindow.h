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
	// topleft corner coordinates
	int m_start_x, m_start_y;
	// sizes
	int m_height, m_width;
	// border symbols
	Border m_border;
	// ncurses window pointer
	WINDOW* m_window;

	// tells whether we were once an rhs in the move constructor
	bool m_is_transferred;

public:
	NcursesWindow(int x, int y, int h, int w, const Border&);
	NcursesWindow(const NcursesWindow&) = delete;
	NcursesWindow(NcursesWindow&&);
	~NcursesWindow();

	NcursesWindow& rebox();

	WINDOW* get() const;
};
