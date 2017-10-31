#pragma once

// An abstract class that defines basic behavior of stuff on the map that
// moves

#include "control/MoveDirection.h"
#include "control/MoveConstants.h"
#include "objects/MapConstants.h"

class AnimateObject
{
protected:
	Coordinate m_x;
	Coordinate m_y;

	PeriodT    m_period;

public:
	virtual MoveDirection tick(void) = 0;
	
	Coordinate get_x(void);
	Coordinate get_y(void);
	Coordinate set_x(Coordinate);
	Coordinate set_y(Coordinate);

	PeriodT    get_period(void);
	PeriodT    set_period(PeriodT);
};

// vim: tw=78
