#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "objects/Map.h"



Map::Map(int H,int W)
{
	m_map.resize(W);
	for(int i = 0; i < W; i++)
		m_map[i].resize(H);
}





















