#include <ncurses.h>
#include <iostream>

int main()
{
 	initscr();
	if (has_colors())
	{
		std::cout << "has colors\n";
		endwin();
		return 0;
	}
	else
	{
		std::cout << "nope\n";
		endwin();
		return 1;
	}
}
