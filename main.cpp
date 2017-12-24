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
				render.redraw_object_pre_move(field, *obj, x, y-1);
				y -= 1;
				obj->set_y(y);
				break;
			case 'j':
			case 's':
			case KEY_DOWN:
				y += 1;
				obj->set_y(y);
				render.redraw_object_post_move(field, x, y-1, *obj);
				break;
			case 'h':
			case 'a':
			case KEY_LEFT:
				x -= 1;
				obj->set_x(x);
				render.redraw_object_post_move(field, x+1, y, *obj);
				break;
			case 'l':
			case 'd':
			case KEY_RIGHT:
				x += 1;
				obj->set_x(x);
				render.redraw_object_post_move(field, x-1, y, *obj);
				break;
			default:
				exit = true;
		}
	}

	return 0;
}
