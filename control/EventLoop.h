#include <vector>
#include <memory>

#include "objects/GameField.h"
#include "inputs/Input.h"

using std::vector;
using std::shared_ptr;

using InputList = vector< shared_ptr<Input> >;


class EventLoop
{
	private:
		GameField m_field;
		InputList m_inputs;

		bool m_keep_playing;


		EventLoop(GameField, InputList);


		bool update_objects(); //updates m_field and m_keep_playing
		void redraw_screen() const;

		EventLoop& before_game(); //dunno what it updates
		EventLoop& start_game();  //updates everything
		EventLoop& after_game();  //dunno either


	public:
		EventLoop& run(); //updates everything
};
