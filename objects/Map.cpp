#include "objects/Map.h"

Map::Map(Coordinate height, Coordinate width)
{
	m_map.resize(width);
	for(auto &line : m_map)
		line.resize(height);
}
Map & Map::change_block(Coordinate height, Coordinate width, Block block)
{
	m_map.at(width).at(height) = block;
	return *this;
}

Coordinate Map::get_width() const
{	
	return m_map.size();
}

Coordinate Map::get_height() const
{
	if (get_width() == 0) 
    		return 0;
	return m_map[0].size();
}


