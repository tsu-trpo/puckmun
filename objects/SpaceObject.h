#pragma once

#include "objects/MapConstants.h"

class SpaceObject
{
protected:
	Coordinate m_x;
	Coordinate m_y;

public:
	Coordinate get_x(void) const;
	Coordinate get_y(void) const;
	Coordinate set_x(Coordinate);
	Coordinate set_y(Coordinate);

	// deleted so that there would be something deleted
	virtual ~SpaceObject() = 0;
};
