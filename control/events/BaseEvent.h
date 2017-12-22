#pragma once

#include <memory>

#include "objects/GameField.h"
#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"
#include "view/GameRender.h"

class BaseEvent
{
public:
	virtual void execute_physics(GameField&) const = 0;
	virtual void execute_graphics(const GameField&, GameRender&) const = 0;
	virtual bool graphics_first() const = 0;

	virtual std::unique_ptr<BaseEvent> clone() const = 0;

	virtual ~BaseEvent() {}
};
