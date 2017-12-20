#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/AnimateObject.h"
#include "control/MoveDirection.h"

class TheMan: public AnimateObject
{	
	MoveDirection m_current;
	MoveDirection m_future;
private:
	TheMan();
	MoveDirection tick();
	void set_current();
	void set_future(MoveDirection);
};
	
