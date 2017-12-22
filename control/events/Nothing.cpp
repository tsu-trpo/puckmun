#include "control/events/Nothing.h"

Events::Nothing::Nothing()
{
}

void Events::Nothing::execute_physics(GameField& f) const
{
	return;
}

void Events::Nothing::execute_graphics(const GameField& f, Render& r) const
{
	return;
}

bool Events::Nothing::graphics_first() const
{
	return false;
}
// vim: tw=78
