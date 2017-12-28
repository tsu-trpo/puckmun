#include "inputs/TheManPlayerInput.h"

#include <chrono>

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


//simple direction error, because optional is only in c++17
class NoDirection
{};

//this function controls how characters map to controls
MoveDirection char_to_direction(int input)
{
	switch (input)
	{
		case 'j':
		case 's':
			return MoveDirection::Down;
		case 'k':
		case 'w':
			return MoveDirection::Up;
		case 'a':
		case 'h':
			return MoveDirection::Left;
		case 'l':
		case 'd':
			return MoveDirection::Right;
	}
	throw NoDirection();
}


Command InpClass::plan(const GameField& field, object_arg)
{
	// TODO: better sleep, write a schedule dividing second into sleep periods

	// as this is called every tick, period with this sleep time should last
	// for slightly more than 1 second
	std::this_thread::sleep_for(std::chrono::milliseconds(9));

	MoveDirection dir;

	try
	{
		dir = char_to_direction(m_data->char_got);
	}
	catch (NoDirection)
	{
		return Commands::make_no_command();
	}
}

// vim: tw=78
