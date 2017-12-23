#include <iostream>
#include <ncurses.h>
#include <typeinfo>

#include "objects/MapLoader.h"
#include "objects/GameField.h"
#include "view/GameRender.h"

int main()
{
	Map map = basic_load_map("../maps/test_map.bpm");

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
