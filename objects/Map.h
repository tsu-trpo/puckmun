#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "objects/Block.h"
#include "objects/MapConstants.h"

using namespace std;

class Map
{
	Coordinate m_height;
	Coordinate m_width;
	vector<vector<Block> > m_map;
		
public:
	Map(Coordinate,Coordinate);
	Map & change_block(Coordinate,Coordinate, Block);
};
