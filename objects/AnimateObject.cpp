#include "objects/AnimateObject.h"

PeriodT AnimateObject :: get_period() const { return m_period; }
PeriodT AnimateObject :: set_period(PeriodT p) { return m_period = p; }

// vim: tw=78
