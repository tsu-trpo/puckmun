#pragma once

#include "objects/GameField.h"
#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"
#include "view/Render.h"

class BaseEvent
{
public:
	virtual void execute_physics(GameField&) const = 0;
	virtual void execute_graphics(const GameField&, Render&) const = 0;
	virtual bool graphics_first() const = 0;

	virtual ~BaseEvent() {}
};
