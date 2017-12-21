#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/AnimateObject.h"

class Ghost: public AnimateObject
{	
	MoveDirection m_current;
public:
	Ghost();
	MoveDirection tick() const;
	Ghost & set_current(MoveDirection);
};
