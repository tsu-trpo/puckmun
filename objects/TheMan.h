#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/AnimateObject.h"

class TheMan: public AnimateObject
{	
	MoveDirection m_current;
	MoveDirection m_next;
private:
	TheMan();
	MoveDirection tick();

};
	
