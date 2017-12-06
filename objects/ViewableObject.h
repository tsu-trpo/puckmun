#pragma once

#include <ncurses.h>

#include "objects/MapConstants.h"

//Interface to print items on screen. Will be extended in the future probably

class ViewableObject
{
public:
	virtual char get_form() = 0;

	//short - тип в ncurses для передачи цветов. Ужас
	virtual short get_bg_color()   = 0;
	virtual short get_body_color() = 0;

	virtual Coordinate get_x(void) = 0;
	virtual Coordinate get_y(void) = 0;
};
