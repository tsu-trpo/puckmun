#pragma once

#include "control/Physics.h"

namespace Physics
{
	PhysicsEvents ghost_man_interaction(const shared_ptr<Ghost>&,
	                                    const shared_ptr<TheMan>&);
}

// vim: tw=78
