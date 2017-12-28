#pragma once

// Event-интерфейс. См. control/events/README.md за описанием наследников

#include <memory>

#include "objects/GameField.h"
#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"
#include "view/GameRender.h"
#include "control/GameStatus.h"

class BaseEvent
{
public:
	virtual GameStatus execute_physics(GameField&) const = 0;
	virtual void execute_graphics(const GameField&, GameRender&) const = 0;
	virtual bool graphics_first() const = 0;

	virtual std::unique_ptr<BaseEvent> clone() const = 0;

	virtual ~BaseEvent() {}
};
