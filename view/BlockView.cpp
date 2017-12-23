#include "view/BlockView.h"

tuple<Color, Color, char> block_view(Block block)
{
	switch (block)
	{
		case Block::Wall:
			return make_tuple(Color::White, Color::White, ' ');
		case Block::Point:
			return make_tuple(Color::White, Color::Black, '.');
		case Block::BigPoint:
			return make_tuple(Color::Red, Color::Black, '*');
		case Block::Space:
			return make_tuple(Color::Black, Color::Black, ' ');
	}
	throw std::logic_error("incorrect block given");
}
