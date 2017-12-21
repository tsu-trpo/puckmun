#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/AnimateObject.h"

class Ghost: public AnimateObject
{	
	MoveDirection m_current;
private:
	Ghost();
	MoveDirection tick();
	Ghost & set_current(MoveDirection);
};
