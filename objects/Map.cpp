#include "objects/Map.h"

Map::Map(int H,int W)
{
	m_height = H;
	m_width = W;
	m_map.resize(W);
	for(int i = 0; i < W; i++)
		m_map[i].resize(H);
}
