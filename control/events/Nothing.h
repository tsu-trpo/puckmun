#pragma once

#include "control/events/BaseEvent.h"

namespace Events
{
	class Nothing : public BaseEvent
	{
	public:
		Nothing();

		void execute_physics(GameField&) const;
		void execute_graphics(const GameField&, Render&) const;
		bool graphics_first() const;
	};
}

// vim: tw=78
