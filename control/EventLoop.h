#pragma once

#include <vector>
#include <memory>
#include <map>

#include "objects/AnimateObject.h"
#include "objects/GameField.h"
#include "inputs/Input.h"
#include "inputs/Command.h"
#include "control/MoveDirection.h"
#include "control/Event.h"

using std::vector;
using std::shared_ptr;
using std::pair;

using InputObject = pair< shared_ptr<Input>, shared_ptr<AnimateObject> >;
using InputList   = vector<InputObject>;


class EventLoop
{
private:
	GameField m_field;
	InputList m_inputs;

	bool m_keep_playing;
	PeriodT m_current_tick;


	EventLoop(const GameField&, const InputList&);


	void redraw_screen()            const;
	vector<Event> move_object(const MoveDirection&,
	                          const shared_ptr<AnimateObject>&) const;

	PeriodT increment_tick(); //updates m_current_tick

	// very unconst methods:
	EventLoop& replan_all_objects();
	EventLoop& move_and_redraw(const vector<Event>&);
	EventLoop& before_game();
	EventLoop& start_game();
	EventLoop& after_game();


public:
	EventLoop& run(); //updates everything
};

// vim: tw=78
