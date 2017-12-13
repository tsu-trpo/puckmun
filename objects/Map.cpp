#include "objects/Map.h"

Map::Map(Coordinate height,Coordinate width)
{

	m_map.resize(width);
	for( auto i : m_map)
		i.resize(height);
}
Map & Map::change_block(Coordinate height,Coordinate width, Block block)
{
	if(height < m_map[0].size() && width < m_map.size())
		m_map.at(width).at(height) = block;
	return *this;
}

Coordinate Map::get_width()
{
	return m_map.size();
}

Coordinate Map::get_height()
{
	return m_map[0].size();
}


