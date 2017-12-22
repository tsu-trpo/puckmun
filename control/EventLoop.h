#pragma once

#include <vector>
#include <memory>
#include <map>

#include "objects/AnimateObject.h"
#include "objects/GameObject.h"
#include "objects/GameField.h"
#include "inputs/Input.h"
#include "inputs/Command.h"
#include "control/MoveDirection.h"
#include "control/Event.h"
#include "view/Render.h"
#include "control/Physics.h"

using std::vector;
using std::shared_ptr;
using std::pair;

using InputObject = pair< shared_ptr<Input>, shared_ptr<GameObject> >;
using InputList   = vector<InputObject>;


class EventLoop
{
private:
	GameField m_field;
	InputList m_inputs;
	Render    m_render;

	bool m_keep_playing;
	PeriodT m_current_tick;
	TimeT m_current_time;

	list<Event> m_scheduled_events;


	EventLoop(const GameField&, const InputList&, const Render&);


	void redraw_screen(const Event&) const;

	PeriodT increment_tick(); //updates m_current_tick

	// very unconst methods:
	EventLoop& replan_all_objects();
	EventLoop& move_and_redraw(const PhysicsEvents&);
	EventLoop& before_game();
	EventLoop& start_game();
	EventLoop& after_game();


public:
	EventLoop& run(); //updates everything
};

// vim: tw=78
