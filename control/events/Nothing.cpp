#include "control/events/Nothing.h"

Events::Nothing::Nothing()
{
}

std::unique_ptr<BaseEvent> Events::Nothing::clone() const
{
	return unique_ptr<BaseEvent>( new Nothing(*this) );
}

void Events::Nothing::execute_physics(GameField&) const
{
	return;
}

void Events::Nothing::execute_graphics(const GameField&, GameRender&) const
{
	return;
}

bool Events::Nothing::graphics_first() const
{
	return false;
}
// vim: tw=78
