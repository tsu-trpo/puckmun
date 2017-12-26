#pragma once

// exception-safe инициализация экрана ncurses, не позволяющая существовать
// более чем одной штуке. Поскольку цвета ncurses также зависят от экрана, то
// он умеет раздавать цветовые пары.

#include <ncurses.h>
#include <map>

#include "view/Color.h"

using std::map;

class NcursesScreen
{
	// number of ncurses screen initialized (must be 1 or zero)
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

	// tells whether we were once an rhs in the move constructor
	bool m_is_transferred;

	static map< MapKey, short > m_registered_colors;
	short m_next_pair_number;

	//register color pair for use
	void register_color_pair(const MapKey&);

public:
	NcursesScreen();
	NcursesScreen(NcursesScreen&&);
	NcursesScreen(const NcursesScreen&) = delete;
	~NcursesScreen();

	//get color pair number for attron() (NOT thread safe!)
	chtype color_pair(Color, Color);

	static size_t get_screens_open();
};

// vim: tw=78
