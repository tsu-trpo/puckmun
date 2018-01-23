#pragma once

#include <memory>

#include "inputs/commands/BaseCommand.h"
#include "objects/AnimateObject.h"

using std::shared_ptr;
using std::unique_ptr;

class NoCommand : public BaseCommand
{
public:
	NoCommand();

	void update(const shared_ptr<AnimateObject>&) override;

	virtual unique_ptr<BaseCommand> clone() const override;
};
