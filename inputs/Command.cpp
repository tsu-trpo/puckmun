#include "inputs/Command.h"

Command::Command(BaseCommand* command)
	: m_command(command)
{
}

void Command::update(const shared_ptr<AnimateObject>& object) const
{
	m_command->update(object);
}
