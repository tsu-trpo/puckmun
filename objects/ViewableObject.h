#pragma once

#include <ncurses.h>

#include "objects/MapConstants.h"
#include "view/Color.h"

//Interface to print items on screen. Will be extended in the future probably

class ViewableObject
{
public:
	virtual char get_form() = 0;

	//fuck fuck fuck old-c-style types
	virtual Color get_bg_color()   const = 0;
	virtual Color get_body_color() const = 0;

	virtual Coordinate get_x(void) const = 0;
	virtual Coordinate get_y(void) const = 0;
};
