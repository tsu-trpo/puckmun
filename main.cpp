#include <memory>
#include <map>

#include "objects/MapLoader.h"
#include "objects/GameField.h"
#include "view/GameRender.h"
#include "objects/TheMan.h"
#include "inputs/TheManPlayerInput.h"
#include "control/EventLoop.h"

using std::shared_ptr;
using std::make_pair;

int main()
{
	Map map = basic_load_map("maps/test_map.bpm");
	
	shared_ptr<TheMan> object (new TheMan);
	GameField field {{object}, map, 5};
	GameRender render (map);
	shared_ptr<TheManPlayerInput> keyboard (new TheManPlayerInput);
	InputList input_pairs {{keyboard, object}};

	EventLoop loop (field, input_pairs, render);
	loop.run();
	
	return 0;
}
