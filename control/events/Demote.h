#pragma once

#include <memory>

#include "control/events/BaseEvent.h"
#include "objects/GameObject.h"

using std::shared_ptr;

namespace Events
{
	class Demote : public BaseEvent
	{
		shared_ptr<GameObject> m_object;
	public:
		Demote(const shared_ptr<GameObject>&);

		std::unique_ptr<BaseEvent> clone() const override;

		void execute_physics(GameField&) const override;
		void execute_graphics(const GameField&, GameRender&) const override;
		bool graphics_first() const override;
	};
}

// vim: tw=78
