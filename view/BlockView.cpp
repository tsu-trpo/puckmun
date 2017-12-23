#include "view/BlockView.h"

tuple<Color, Color, char> block_view(Block block)
{
	switch (block)
	{
		case Block::Wall:
			return make_tuple(Color::White, Color::White, 'w');
		case Block::Point:
			return make_tuple(Color::White, Color::Black, 'p');
		case Block::BigPoint:
			return make_tuple(Color::Red, Color::Black, 'b');
		case Block::Space:
			return make_tuple(Color::Black, Color::Black, 's');
	}
	throw std::logic_error("incorrect block given");
}
