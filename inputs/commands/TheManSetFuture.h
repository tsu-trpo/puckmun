#pragma once

#include <memory>

#include "inputs/commands/BaseCommand.h"
#include "objects/AnimateObject.h"
#include "control/MoveDirection.h"

using std::shared_ptr;
using std::unique_ptr;

class TheManSetFuture : public BaseCommand
{
	MoveDirection m_to_set;
public:
	TheManSetFuture(MoveDirection);

	void update(const shared_ptr<AnimateObject>&) override;

	virtual unique_ptr<BaseCommand> clone() const override;
};

// vim: tw=78
