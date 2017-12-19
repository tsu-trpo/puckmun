#pragma once

#include <vector>
#include <memory>

#include "AnimateObject.h"

using std::shared_ptr;

class GameField
{
	std::vector< shared_ptr<AnimateObject> > m_objects;

public:
	const std::vector< shared_ptr<AnimateObject> >& get_objects();
};
