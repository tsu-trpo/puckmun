#include "objects/Map.h"

Map::Map(Coordinate height,Coordinate width)
{
//	m_height = height;
//	m_width = width;
	m_map.resize(width);
//	for(Coordinate i = 0; i < width; i++)
	for( auto i : m_map)
		i->resize(height);
}
Map & Map::change_block(Coordinate height,Coordinate width, Block block)
{
//	if(height >= 0 && height < m_height && width >= 0 && width < m_width)
	if(height < m_map[i].size && wight < m_map.size)
		m_map.at(width).at(height) = block;
	return *this;
}
