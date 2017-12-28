#include "inputs/commands/NoCommand.h"

NoCommand::NoCommand()
{}


unique_ptr<BaseCommand> NoCommand::clone() const
{
	return unique_ptr<BaseCommand>( new NoCommand(*this) );
}


void NoCommand::update(const shared_ptr<AnimateObject>&)
{
}

// vim: tw=78
