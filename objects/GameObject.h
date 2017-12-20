#pragma once

//main game obbject, both animate && viewable

#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"

class GameObject : public AnimateObject, public ViewableObject
{
public:
	virtual GameObject& promote();
	virtual GameObject& demote();
};
