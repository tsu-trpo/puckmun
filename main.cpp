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
	Map map = basic_load_map("maps/test_map.bpm");

	shared_ptr<ExampleObject> obj1 (new ExampleObject);
	shared_ptr<ExampleObject> obj2 (new ExampleObject);

	Coordinate x1 = 1, y1 = 1;
	Coordinate x2 = 3, y2 = 3;
	obj1->set_x(x1);
	obj1->set_y(y1);
	obj2->set_x(x2);
	obj2->set_y(y2);

	GameField field {{obj1, obj2}, map, 0};
	GameRender pre_render (map);
	// test how move constructor behaves
	GameRender render = std::move(pre_render);

	render.redraw_complete(field);
	render.print_status("Here comes dat boi!");

	bool exit = false;
	while (!exit)
	{
		int c = wgetch(stdscr);
		switch (c)
		{
			case 'k':
			case 'w':
			case KEY_UP:
				render.redraw_object_pre_move(field, *obj1, x1, y1-1);
				y1 -= 1;
				obj1->set_y(y1);
				render.redraw_object_pre_move(field, *obj2, x2, y2-1);
				y2 -= 1;
				obj2->set_y(y2);
				break;
			case 'j':
			case 's':
			case KEY_DOWN:
				y1 += 1;
				obj1->set_y(y1);
				render.redraw_object_post_move(field, x1, y1-1, *obj1);
				y2 += 1;
				obj2->set_y(y2);
				render.redraw_object_post_move(field, x2, y2-1, *obj2);
				break;
			case 'h':
			case 'a':
			case KEY_LEFT:
				x1 -= 1;
				obj1->set_x(x1);
				render.redraw_object_post_move(field, x1+1, y1, *obj1);
				x2 -= 1;
				obj2->set_x(x2);
				render.redraw_object_post_move(field, x2+1, y2, *obj2);
				break;
			case 'l':
			case 'd':
			case KEY_RIGHT:
				x1 += 1;
				obj1->set_x(x1);
				render.redraw_object_post_move(field, x1-1, y1, *obj1);
				x2 += 1;
				obj2->set_x(x2);
				render.redraw_object_post_move(field, x2-1, y2, *obj2);
				break;
			default:
				exit = true;
		}
	}

	return 0;
}
