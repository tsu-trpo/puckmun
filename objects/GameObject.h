#pragma once

//main game obbject, both animate && viewable

#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"

class GameObject : public AnimateObject, public ViewableObject
{
	Coordinate get_x() const override {return AnimateObject::get_x();}
	Coordinate get_y() const override {return AnimateObject::get_y();}

	virtual GameObject& promote();
	virtual GameObject& demote();
};

// vim: tw=78
