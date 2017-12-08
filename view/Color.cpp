#include "view/Color.h"

short ncurses_color(Color color)
{
	switch (color)
	{
		case Color::Black:
			return COLOR_BLACK;
			break;
		case Color::Red:
			return COLOR_RED;
			break;
		case Color::Green:
			return COLOR_GREEN;
			break;
		case Color::Yellow:
			return COLOR_YELLOW;
			break;
		case Color::Blue:
			return COLOR_BLUE;
			break;
		case Color::Magenta:
			return COLOR_MAGENTA;
			break;
		case Color::Cyan:
			return COLOR_CYAN;
			break;
		case Color::White:
			return COLOR_WHITE;
			break;
		default:
			// ehhh what to do what to do
			// well it should never come here
			return ERR;
	}
}
