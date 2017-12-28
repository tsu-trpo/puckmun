#include <memory>
#include <map>

#include "objects/MapLoader.h"
#include "objects/GameField.h"
#include "view/GameRender.h"
#include "objects/TheMan.h"
#include "objects/Ghost.h"
#include "inputs/TheManPlayerInput.h"
#include "inputs/GhostInput.h"
#include "control/EventLoop.h"

using std::shared_ptr;
using std::make_pair;

int main()
{
	Map map = basic_load_map("maps/test_map.bpm");
	
	shared_ptr<TheMan> man (new TheMan);
	man->set_x(5);
	man->set_y(5);
	man->set_period(60);

	shared_ptr<Ghost> ghost (new Ghost);
	ghost->set_x(10);
	ghost->set_y(2);
	ghost->set_period(30);

	GameField field {{man, ghost}, map, 36};
	GameRender render (map);

	shared_ptr<TheManPlayerInput> keyboard (new TheManPlayerInput);
	shared_ptr<GhostInput> ai (new GhostInput);

	InputList input_pairs {{keyboard, man}, {ai, ghost}};

	EventLoop loop (field, input_pairs, render);
	loop.run();
	
	return 0;
}
