#include "inputs/Command.h"

Command::Command(unique_ptr<BaseCommand> command)
	: m_command(std::move(command))
{
}

void Command::update(const shared_ptr<AnimateObject>& object) const
{
	m_command->update(object);
}
