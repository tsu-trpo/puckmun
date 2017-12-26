#pragma once

#include <memory>

#include "objects/AnimateObject.h"

using std::shared_ptr;
using std::unique_ptr;

class BaseCommand
{
public:
	virtual void update(const shared_ptr<AnimateObject>&) = 0;

	virtual unique_ptr<BaseCommand> clone() const = 0;

	virtual ~BaseCommand() {}
};
