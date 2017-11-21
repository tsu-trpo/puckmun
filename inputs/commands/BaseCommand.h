#pragma once

#include <memory>

#include "objects/AnimateObject.h"

using std::shared_ptr;

class BaseCommand
{
public:
	virtual void update(const shared_ptr<AnimateObject>&) = 0;
};
