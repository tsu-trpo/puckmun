#include "control/Interactions.h"

#include "objects/TheMan.h"
#include "objects/Ghost.h"

namespace Physics
{
	PhysicsEvents ghost_man_interaction(const shared_ptr<Ghost>& ghost,
	                                    const shared_ptr<TheMan>& man)
	{
		if (ghost->get_demoted())
		{
			// poor ghost just wants to run
			return PhysicsEvents { {}, {} };
		}
		if (man->get_promoted())
		{
			// kill ghost by op player
			auto event = Events::make_demote(ghost);
			return PhysicsEvents { std::list<Event>{event}, {} };
		}
		else
		{
			// ghost eats dude, nom nom nom
			return { {Events::make_die_hero()}, {} };
		}
	}

}
