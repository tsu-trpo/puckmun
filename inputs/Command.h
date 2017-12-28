#pragma once

// A thin wrapper against BaseCommand as to not carry a lot of fucking
// pointers around

#include <memory>

#include "objects/AnimateObject.h"
#include "inputs/commands/BaseCommand.h"

using std::shared_ptr;
using std::unique_ptr;

class Command
{
	unique_ptr<BaseCommand> m_command;

public:
	Command(unique_ptr<BaseCommand>);
	Command(const Command&);

	// execute command: update the object's next actions
	void update(const shared_ptr<AnimateObject>&) const;
};

namespace Commands
{
	Command make_ghost_set_current(MoveDirection);
}
// vim: tw=78
