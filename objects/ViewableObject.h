#pragma once

#include <ncurses.h>

#include "objects/SpaceObject.h"
#include "objects/MapConstants.h"
#include "view/Color.h"

//Interface to print items on screen. Will be extended in the future probably

class ViewableObject : virtual public SpaceObject
{
public:
	//non-const as it may be useful for animations
	virtual char get_form() const = 0;
	virtual Color get_bg_color() const   = 0;
	virtual Color get_body_color() const = 0;
};

// vim: tw=78
