#pragma once

#include "control/events/BaseEvent.h"
#include "objects/GameField.h"
#include "objects/MapConstants.h"
#include "objects/Block.h"

namespace Events
{
	class AddWall : public BaseEvent
	{
		Coordinate m_x;
		Coordinate m_y;
		Block  m_block;

	public:
		AddWall(Coordinate, Coordinate, Block);

		std::unique_ptr<BaseEvent> clone() const override;

		void execute_physics(GameField&) const override;
		void execute_graphics(const GameField&, Render&) const override;
		bool graphics_first() const;
	};
}

// vim: tw=78
