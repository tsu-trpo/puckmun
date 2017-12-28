#include "control/events/DieHero.h"

Events::DieHero::DieHero()
{
}

std::unique_ptr<BaseEvent> Events::DieHero::clone() const
{
	return unique_ptr<BaseEvent>( new DieHero(*this) );
}

GameStatus Events::DieHero::execute_physics(GameField&) const
{
	// do nothing but lose
	return GameStatus::Lost;
}

void Events::DieHero::execute_graphics(const GameField& f, GameRender& r) const
{
	r.redraw_complete(f);
}

bool Events::DieHero::graphics_first() const
{
	return true;
}
// vim: tw=78
