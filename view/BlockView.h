#pragma once

#include <ncurses.h>
#include <tuple>

#include "objects/Block.h"
#include "view/Color.cpp"

using std::tuple;
using std::make_tuple;

// return block background, foreground colors and character
tuple<Color, Color, char> block_view(Block);

// vim: tw=78
