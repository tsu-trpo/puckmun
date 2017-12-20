#include "objects/AnimateObject.h"

Coordinate AnimateObject :: get_x() const { return m_x; }
Coordinate AnimateObject :: set_x(Coordinate x) { return m_x = x; }

Coordinate AnimateObject :: get_y() const { return m_y; }
Coordinate AnimateObject :: set_y(Coordinate y) { return m_y = y; }

PeriodT AnimateObject :: get_period() const { return m_period; }
PeriodT AnimateObject :: set_period(PeriodT p) { return m_period = p; }

// vim: tw=78
