#pragma once

#include "control/events/BaseEvent.h"

namespace Events
{
	class EatPoint : public BaseEvent
	{
		Coordinate m_x;
		Coordinate m_y;
	public:
		EatPoint(Coordinate, Coordinate);

		void execute_physics(GameField&) const;
		void execute_graphics(const GameField&, Render&) const;
		bool graphics_first() const;
	};
}

// vim: tw=78
