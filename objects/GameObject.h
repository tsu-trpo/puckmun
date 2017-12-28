#pragma once

//main game obbject, both animate && viewable

#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"

class GameObject : public AnimateObject, public ViewableObject
{
public:
	virtual GameObject& promote() = 0;
	virtual GameObject& demote() = 0;

	// tells if this object will decrease the points amount on the map
	virtual bool eats_points() const = 0;
};

// vim: tw=78
