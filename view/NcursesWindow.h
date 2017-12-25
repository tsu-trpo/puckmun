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

public:
	NcursesWindow(int x, int y, int h, int w, const Border&);
	~NcursesWindow();

	NcursesWindow& rebox();

	WINDOW* get() const;
};
