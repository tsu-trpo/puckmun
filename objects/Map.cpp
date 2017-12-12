#include "objects/Map.h"

Map::Map(Coordinate height,Coordinate width)
{
	m_height = height;
	m_width = width;
	m_map.resize(width);
	for(Coordinate i = 0; i < width; i++)
		m_map[i].resize(height);
}
Map Map::change_block(Coordinate height,Coordinate width, Block block)
{
	if(height >= 0 && height < m_height && width >= 0 && width < m_width)
		m_map[width][height] = block;
	return *this;
}
