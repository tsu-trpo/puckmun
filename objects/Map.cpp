#include "objects/Map.h"

Map::Map(Coordinate height,Coordinate width)
{
	m_height = height;
	m_width = width;
	m_map.resize(width);
	for(Coordinate i = 0; i < width; i++)
		m_map[i].resize(height);
}
