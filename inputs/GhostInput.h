#pragma once

#include <memory>

#include "inputs/Input.h"
#include "objects/Ghost.h"

using std::shared_ptr;

class GhostInput : public Input
{
public:
	GhostInput() = default;

	Command plan(const GameField&, const shared_ptr<const AnimateObject>&) override;
};

// vim: tw=78
