#pragma once

#include <memory>

#include "inputs/Command.h"
#include "objects/AnimateObject.h"
#include "objects/GameField.h"

using std::shared_ptr;

class Input
{
public:
	virtual Command plan(const GameField&, const shared_ptr<AnimateObject>&) = 0;
};
