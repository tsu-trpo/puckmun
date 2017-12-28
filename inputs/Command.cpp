#include "inputs/Command.h"

#include "errors/ErrorConstants.h"
#include "inputs/commands/NoCommand.h"
#include "inputs/commands/TheManSetCurrent.h"


Command::Command(unique_ptr<BaseCommand> command)
	: m_command (std::move(command))
{
}

Command::Command(const Command& other)
	: m_command (other.m_command->clone())
{
}

void Command::update(const shared_ptr<AnimateObject>& object) const
{
	if (!object)
		throw std::invalid_argument( ERR_HEADER "passed null pointer as object" );
	m_command->update(object);
}

namespace Commands
{
	Command make_no_command()
	{
		return Command( unique_ptr<NoCommand>(
		                  new NoCommand)
		              );
	}

	Command make_the_man_set_current(MoveDirection dir)
	{
		return Command( unique_ptr<TheManSetCurrent>(
		                  new TheManSetCurrent(dir))
		              );
	}
}
