#include "view/NcursesWindow.h"

#include "view/NcursesScreen.h"
#include "errors/GameRender-errors.h"
#include "errors/NcursesError.h"

using Border = NcursesWindow::Border;

NcursesWindow::NcursesWindow(int x, int y, int w, int h, const Border& border)
	: m_border  (border)
	, m_is_transferred (false)
{
	if (NcursesScreen::get_screens_open() == 0)
	{
		throw ScreenError("Trying to create window with no screens open");
	}

	// create window
	m_window = newwin(h, w, y, x);
	// draw a box around it
	wborder(m_window, m_border.left,    m_border.right,
	                  m_border.top,     m_border.bottom,
	                  m_border.topleft, m_border.topright,
	                  m_border.botleft, m_border.botright);
	// show it
	wrefresh(m_window);
	refresh();
}

NcursesWindow::NcursesWindow(NcursesWindow&& other)
	: m_border         (std::move (other.m_border))
	, m_window         (std::move (other.m_window))
	, m_is_transferred (false)
	
{
	// okay, so what if we move already transferred window?
	if (other.m_is_transferred) m_is_transferred = true;

	other.m_is_transferred = true;
	// window is initialized, control of window is transferred
	// nothing to do
}

NcursesWindow::~NcursesWindow()
{
	if (m_is_transferred) return;

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
	wborder(m_window, m_border.left,    m_border.right,
	                  m_border.top,     m_border.bottom,
	                  m_border.topleft, m_border.topright,
	                  m_border.botleft, m_border.botright);
	wrefresh(m_window);

	return *this;
}
