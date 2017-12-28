#pragma once

#include "control/events/BaseEvent.h"

namespace Events
{
	class Nothing : public BaseEvent
	{
	public:
		Nothing();

		std::unique_ptr<BaseEvent> clone() const override;

		GameStatus execute_physics(GameField&) const override;
		void execute_graphics(const GameField&, GameRender&) const override;
		bool graphics_first() const override;
	};
}

// vim: tw=78
