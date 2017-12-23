#include <iostream>
#include <ncurses.h>
#include <typeinfo>

#include "objects/MapLoader.h"
#include "objects/GameField.h"
#include "view/GameRender.h"

int main()
{
	Map map = basic_load_map("../maps/test_map.bpm");
	print_map(map);

	GameField field {{}, map, 0};
	GameRender render;

	render.redraw_complete(field);
	getch();

	return 0;
}
