#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "objects/Block.h"
#include "objects/MapConstants.h"

using namespace std;

class Map
{
	vector<vector<Block> > m_map;
		
public:
	Map(Coordinate, Coordinate);
	Map & change_block(Coordinate, Coordinate, Block);
	Coordinate get_height();
	Coordinate get_width();
};
