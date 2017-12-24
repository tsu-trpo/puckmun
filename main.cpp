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
	obj->set_x(5);
	obj->set_y(10);

	GameField field {{}, map, 0};
	GameRender render;

	wprintw(stdscr, "woah woah woah");
	refresh();
	wgetch(stdscr);
	render.redraw_complete(field);
	mvwprintw(stdscr, 0, 0, "that's all");
	refresh();
	wgetch(stdscr);

	return 0;
}
