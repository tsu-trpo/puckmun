#include "view/NcursesWindow.h"

#include "view/NcursesScreen.h"
#include "errors/GameRender-errors.h"
#include "errors/NcursesError.h"

NcursesWindow::NcursesWindow(int x, int y, int w, int h)
	: m_start_x (x)
	, m_start_y (y)
	, m_height  (h)
	, m_width   (w)
{
	if (NcursesScreen::screens_open == 0)
	{
		throw ScreenError("Trying to create window with no screens open");
	}

	// create window
	m_window = newwin(m_height, m_width, m_start_y, m_start_x);
	// draw a box around it
	box(m_window, 0, 0);
	// show it
	wrefresh(m_window);
	refresh();
}

NcursesWindow::~NcursesWindow()
{
	// delete the border
	wborder(m_window, ' ',' ',  //left, right
	                  ' ',' ',  //top, bottom
	                  ' ',' ',  //top corners:    left, right
	                  ' ',' '); //bottom corners: left, right
	//show deletion
	wrefresh(m_window);
	//delete window
	delwin(m_window);
}

WINDOW* NcursesWindow::get() const
{
	return m_window;
}

NcursesWindow& NcursesWindow::rebox()
{
	box(m_window, 0, 0);
	wrefresh(m_window);

	return *this;
}
