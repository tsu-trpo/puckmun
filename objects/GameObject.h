#pragma once

//main game obbject, both animate && viewable

#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"

class GameObject : public virtual AnimateObject, public virtual ViewableObject
{
};
