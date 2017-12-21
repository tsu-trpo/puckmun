#pragma once

#include "objects/GameField.h"
#include "objects/AnimateObject.h"
#include "objects/ViewableObject.h"
#include "view/Render.h"

class BaseEvent
{
public:
	virtual void execute_physics(GameField&) const;
	virtual void execute_graphics(const GameField&, Render&) const;
};
