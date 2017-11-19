#pragma once

#include <vector>
#include <memory>
#include <map>

#include "objects/AnimateObject.h"
#include "objects/GameField.h"
#include "inputs/Input.h"
#include "inputs/Command.h"

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


	EventLoop(const GameField&, const InputList&);


	bool move_objects(); //updates m_field and m_keep_playing
	void update_object_plan(const Command&, const shared_ptr<AnimateObject>&); //updates m_field && m_inputs by updating second argument
	void redraw_screen() const;

	EventLoop& before_game(); //dunno what it updates
	EventLoop& start_game();  //updates everything
	EventLoop& after_game();  //dunno either


public:
	EventLoop& run(); //updates everything
};
