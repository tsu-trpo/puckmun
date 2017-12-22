#pragma once

#include <ncurses.h>

#include "objects/MapConstants.h"
#include "view/Color.h"

//Interface to print items on screen. Will be extended in the future probably

class ViewableObject
{
public:
	//non-const as it may be useful for animations
	virtual char get_form() = 0;
	virtual Color get_bg_color()   = 0;
	virtual Color get_body_color() = 0;

	virtual Coordinate get_x(void) const = 0;
	virtual Coordinate get_y(void) const = 0;
};

// vim: tw=78
