#pragma once

// при создании создаёт поток, считывающий нажатия клавиатуры, и при вызове
// plan преобразует их в нажатия
// ОЧЕНЬ не рекомендуется создавать два этих объекта: экрану может стать плохо

#include <memory>
#include <thread>

#include "inputs/Input.h"
#include "inputs/Command.h"
#include "objects/AnimateObject.h"
#include "objects/GameField.h"
#include "view/NcursesScreen.h"

using std::shared_ptr;
using object_arg = const shared_ptr<const AnimateObject>&;


class TheManPlayerInput : public Input
{
	// data shared between this class and its updater thread
	struct ThreadData
	{
		bool should_exit;
		int  char_got;
	};

	// routine in updater thread
	friend void update_routine(shared_ptr<ThreadData>);

	// the screen must exists for this to be meaningful
	NcursesScreen m_personal_screen;
	// data shared between class instance && updater thread
	shared_ptr<ThreadData> m_data;
	// key updating thread
	std::thread m_update_thread;

public:
	TheManPlayerInput();
	TheManPlayerInput(const TheManPlayerInput&) = delete;
	TheManPlayerInput(TheManPlayerInput&&) = default;
	~TheManPlayerInput();

	Command plan(const GameField&, const shared_ptr<const AnimateObject>&)
		override;
};

// vim: tw=78
