#include "objects/Map.h"

Map::Map(Coordinate Height,Coordinate Width)
{
	m_height = Height;
	m_width = Width;
	m_map.resize(W);
	for(int i = 0; i < W; i++)
		m_map[i].resize(H);
}

