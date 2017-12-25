#include "objects/SpaceObject.h"

Coordinate SpaceObject::get_x() const { return m_x; }
Coordinate SpaceObject::set_x(Coordinate x) { return m_x = x; }

Coordinate SpaceObject::get_y() const { return m_y; }
Coordinate SpaceObject::set_y(Coordinate y) { return m_y = y; }

SpaceObject::~SpaceObject() {}

// vim: tw=78
