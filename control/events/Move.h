#pragma once

#include <memory>

#include "control/events/BaseEvent.h"
#include "control/MoveDirection.h"
#include "objects/GameObject.h"

using std::shared_ptr;

namespace Events
{
	class Move : public BaseEvent
	{
		MoveDirection m_direction;
		shared_ptr<GameObject> m_object;
		Coordinate m_new_x;
		Coordinate m_new_y;

	public:
		Move(const shared_ptr<GameObject>&, MoveDirection);

		std::unique_ptr<BaseEvent> clone() const override;

		void execute_physics(GameField&) const override;
		void execute_graphics(const GameField&, Render&) const override;
		bool graphics_first() const;
	};
}

// vim: tw=78
