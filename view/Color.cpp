#include "view/Color.h"

#include "errors/ErrorConstants.h"

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
			throw std::logic_error(ERR_HEADER "unexpected color value in case section\n");
	}
}
