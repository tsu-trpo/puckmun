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

		std::unique_ptr<BaseEvent> clone() const override;

		void execute_physics(GameField&) const override;
		void execute_graphics(const GameField&, Render&) const override;
		bool graphics_first() const override;
	};
}

// vim: tw=78
