#pragma once

#include <vector>
#include <memory>

#include "AnimateObject.h"
#include "objects/Map.h"

using std::shared_ptr;

struct GameField
{
	std::vector< shared_ptr<AnimateObject> > objects;
	Map map;
};
