#include "inputs/TheManPlayerInput.h"

#include <chrono>

#include "errors/ErrorConstants.h"
#include "objects/TheMan.h"

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
	// will exit soon upon seeing the flag
	m_update_thread.join();
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


std::tuple<Coordinate, Coordinate>
	next_coordinates(Coordinate x, Coordinate y, MoveDirection dir)
{
	switch (dir)
	{
		case MoveDirection::Up:
			return std::make_tuple(x, y-1);
		case MoveDirection::Down:
			return std::make_tuple(x, y+1);
		case MoveDirection::Left:
			return std::make_tuple(x-1, y);
		case MoveDirection::Right:
			return std::make_tuple(x+1, y);
	}
	throw std::logic_error(ERR_HEADER
		"Unexpected case when reviewing directions");
}


//simple direction error, because optional datatype is only in c++17
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


// returns commandto update appropriate man field based on if there is a wall
// in the path
Command set_if_no_wall(const GameField& field, MoveDirection dir,
		               Coordinate x, Coordinate y)
{
	std::tie(x, y) = next_coordinates(x, y, dir);

	// cooridinates are unsigned, don't compare to 0
	if (x > field.map.get_width() || y > field.map.get_height())
	{
		// do not intend to go where no path lies (!)
		return Commands::make_no_command();
	}

	if (field.map.at(x, y) == Block::Wall)
	{
		return Commands::make_no_command();
	}
	else
	{
		return Commands::make_the_man_set_current(dir);
	}
}


Command InpClass::plan(const GameField& field, object_arg pre_object_ptr)
{
	// TODO: better sleep, write a schedule dividing second into sleep periods

	// as this is called every tick, period with this sleep time should last
	// for slightly more than 1 second
	std::this_thread::sleep_for(std::chrono::milliseconds(8));


	// input methods are unique for different objects because objects
	// themselves are very different, so pointer cast is the only way
	auto object_ptr =
		std::dynamic_pointer_cast<const TheMan, const AnimateObject>
			(pre_object_ptr);
	if (!object_ptr)
	{
		throw std::logic_error(ERR_HEADER
			"possibly passed an incorrect object type");
	}


	MoveDirection dir;
	try
	{
		// char_got contains the most recent character read
		//may throw NoDirection
		dir = char_to_direction(m_data->char_got);
	}
	catch (NoDirection)
	{
		return Commands::make_no_command();
	}

	return set_if_no_wall(field, dir,
	                      object_ptr->get_x(), object_ptr->get_y());
}

// vim: tw=78
