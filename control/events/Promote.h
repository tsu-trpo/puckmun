#pragma once

#include <memory>

#include "control/events/BaseEvent.h"
#include "objects/GameObject.h"

using std::shared_ptr;

namespace Events
{
	class Promote : public BaseEvent
	{
		shared_ptr<GameObject> m_object;
	public:
		Promote(const shared_ptr<GameObject>&);

		void execute_physics(GameField&) const;
		void execute_graphics(const GameField&, Render&) const;
		bool graphics_first() const;
	};
}

// vim: tw=78
