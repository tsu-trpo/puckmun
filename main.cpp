<<<<<<< HEAD
#include <iostream>

#include "objects/MapLoader.h"

int main()
{
	Map map = basic_load_map("maps/test_map.bpm");
	print_map(map);

	return 0;
}
