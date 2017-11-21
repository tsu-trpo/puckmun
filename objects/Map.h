#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "objects/Block.h"

using namespace std;

class Map
{
	int m_height;
	int m_width;
	vector<vector<Block>> m_map;
		
public:
	Map(int,int);
};
