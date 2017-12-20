#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"
#include "objects/Map.h"

using std::shared_ptr;

struct GameField
{
	std::vector< shared_ptr<GameObject> > objects;
	Map map;
};
