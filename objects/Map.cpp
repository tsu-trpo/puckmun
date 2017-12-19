#include "objects/Map.h"

Map::Map(Coordinate height,Coordinate width)
{

	m_map.resize(width);
	for( auto &line : m_map)
		line->resize(height);
}
Map & Map::change_block(Coordinate height,Coordinate width, Block block)
{
	if(height < get_width() && width < get_height())
		m_map.at(width).at(height) = block;
	return *this;
}

Coordinate Map::get_width()
{	
	return m_map.size();
}

Coordinate Map::get_height()
{
	
	if (get_width() == 0) 
    		return 0;
	return m_map[0].size();
}


