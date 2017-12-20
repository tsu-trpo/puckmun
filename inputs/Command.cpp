#include "inputs/Command.h"

#include "error.h"

Command::Command(unique_ptr<BaseCommand> command)
	: m_command(std::move(command))
{
}

void Command::update(const shared_ptr<AnimateObject>& object) const
{
	if (!object)
		throw std::invalid_argument( ERR_HEADER "passed null pointer as object" );
	m_command->update(object);
}
