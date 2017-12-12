#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "objects/Block.h"
#include "control/MoveDirection.h"
#include "objects/MapConstants.h"
#include "control/MoveConstants.h"
#include "objects/AnimateObject.h"
using namespace std;

class Ghost: public AnimateObject
{	
	MoveDirection m_current;
private:
	Ghost();
	MoveDirection tick();

};

