#pragma once

#include <ncurses.h>

class NcursesWindow
{
	// topleft corner coordinates
	int m_start_x, m_start_y;
	// sizes
	int m_height, m_width;
	// ncurses window pointer
	WINDOW* m_window;

public:
	NcursesWindow(int x, int y, int h, int w);
	~NcursesWindow();

	NcursesWindow& rebox();

	WINDOW* get() const;
};
