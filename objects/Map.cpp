#include "objects/Map.h"

Map::Map(Coordinate width, Coordinate height)
{
	m_map.resize(width);
	for(auto &line : m_map)
		line.resize(height);
}
Map & Map::change_block(Coordinate x, Coordinate y, Block block)
{
	m_map.at(x).at(y) = block;
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

Block Map::at(Coordinate x, Coordinate y) const
{
	return m_map.at(x).at(y);
}
