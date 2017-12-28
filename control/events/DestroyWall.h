#pragma once

#include "control/events/BaseEvent.h"
#include "objects/GameField.h"
#include "objects/MapConstants.h"
#include "objects/Block.h"

namespace Events
{
	class DestroyWall : public BaseEvent
	{
		Coordinate m_x;
		Coordinate m_y;

	public:
		DestroyWall(Coordinate, Coordinate);

		std::unique_ptr<BaseEvent> clone() const override;

		GameStatus execute_physics(GameField&) const override;
		void execute_graphics(const GameField&, GameRender&) const override;
		bool graphics_first() const override;
	};
}

// vim: tw=78
