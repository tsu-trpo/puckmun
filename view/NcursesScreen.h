#pragma once

// exception-safe инициализация экрана ncurses, не позволяющая существовать
// более чем одной штуке

#include <ncurses.h>
#include <map>

#include "view/Color.h"

using std::map;

class NcursesScreen
{
	static size_t m_screens_open;

	// comparable pair of two colors
	struct MapKey
	{
		Color foreground;
		Color background;
		bool operator< (const MapKey& r) const
		{
			if (foreground == r.foreground)
			{
				return (unsigned)background < (unsigned)r.background;
			}
			return (unsigned)foreground < (unsigned)r.foreground;
		}
	};

	// tells whether we're an rhs in the move constructor
	bool m_is_transferred;

	map< MapKey, short > m_registered_colors;
	short m_next_pair_number;

public:
	NcursesScreen();
	NcursesScreen(NcursesScreen&&);
	NcursesScreen(const NcursesScreen&) = delete;
	~NcursesScreen();

	//register color pair for use
	NcursesScreen& register_color_pair(Color, Color);
	//get color pair number for attron()
	chtype color_pair(Color, Color);
};

// vim: tw=78
