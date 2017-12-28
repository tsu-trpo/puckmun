#include "inputs/TheManPlayerInput.h"

using InpClass = TheManPlayerInput;

// why do i need double declaration?
void update_routine(shared_ptr<InpClass::ThreadData>);


InpClass::TheManPlayerInput()
	: m_personal_screen ()
	, m_data (make_shared<ThreadData>(ThreadData {false, ERR}))
	, m_update_thread (update_routine, m_data)
{
	// characters are not printed after typing
	noecho();
	// set timeout to getchar procedures. After 1 second ERR will be returned
	timeout(1);
	// as nothing else is supposed to read enything from keyboard, no
	// unsetting timeout is neccesary =)
}

InpClass::~TheManPlayerInput()
{
	m_data->should_exit = true;
}


void update_routine(shared_ptr<InpClass::ThreadData> data)
{
	while(!data->should_exit)
	{
		int got = wgetch(stdscr);

		// the timeout set in constructor specifies that after it ERR will be
		// returned. So we skip returned ERR as it was no key pressed by user
		if (got != ERR)
		{
			data->char_got = got;
		}
	}
}

// vim: tw=78
