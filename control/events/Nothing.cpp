#include "control/events/Nothing.h"

Events::Nothing::Nothing()
{
}

void Events::Nothing::execute_physics(GameField&) const
{
	return;
}

void Events::Nothing::execute_graphics(const GameField&, Render&) const
{
	return;
}

bool Events::Nothing::graphics_first() const
{
	return false;
}
// vim: tw=78
