// A thin wrapper against BaseCommand as to not carry a lot of fucking
// pointers around
#pragma once

#include <memory>

#include "objects/AnimateObject.h"
#include "inputs/commands/BaseCommand.h"

using std::shared_ptr;
using std::unique_ptr;

class Command
{
	unique_ptr<BaseCommand> m_command;

public:
	void update(const shared_ptr<AnimateObject>&) const;

	Command(BaseCommand*);
};
