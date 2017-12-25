#pragma once

// An abstract class that defines basic behavior of stuff on the map that
// moves

#include "objects/SpaceObject.h"
#include "control/MoveDirection.h"
#include "control/MoveConstants.h"

class AnimateObject : virtual public SpaceObject
{
	PeriodT    m_period;

public:
	virtual MoveDirection tick(void) = 0;
	
	PeriodT    get_period(void) const;
	PeriodT    set_period(PeriodT);

	virtual ~AnimateObject() {}
};

// vim: tw=78
