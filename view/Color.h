#pragma once

#include <stdexcept>
#include <ncurses.h>

// defines strict colors and a function to convert them to ncurses colors

enum struct Color
{
	Black,
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White
};

//convert to ncurses color
short ncurses_color(Color);
