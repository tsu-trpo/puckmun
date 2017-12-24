#include <iostream>
#include <ncurses.h>
#include <memory>

#include "objects/MapLoader.h"
#include "objects/GameField.h"
#include "view/GameRender.h"
#include "objects/ExampleObject.h"

using std::shared_ptr;

int main()
{
	Map map = basic_load_map("../maps/test_map.bpm");

	shared_ptr<ExampleObject> obj (new ExampleObject);

	Coordinate x = 1, y = 1;
	obj->set_x(x);
	obj->set_y(y);

	GameField field {{obj}, map, 0};
	GameRender render;


	render.redraw_complete(field);

	bool exit = false;
	while (!exit)
	{
		int c = wgetch(stdscr);
		switch (c)
		{
			case 'k':
			case 'w':
			case KEY_UP:
				y -= 1;
				obj->set_y(y);
				render.redraw_complete(field);
				break;
			case 'j':
			case 's':
			case KEY_DOWN:
				y += 1;
				obj->set_y(y);
				render.redraw_complete(field);
				break;
			case 'h':
			case 'a':
			case KEY_LEFT:
				x -= 1;
				obj->set_x(x);
				render.redraw_complete(field);
				break;
			case 'l':
			case 'd':
			case KEY_RIGHT:
				x += 1;
				obj->set_x(x);
				render.redraw_complete(field);
				break;
			default:
				exit = true;
		}
	}

	return 0;
}
