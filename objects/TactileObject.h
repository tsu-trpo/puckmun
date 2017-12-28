#pragma once

// для объектов, которые могут друг друга потрогать

#include <memory>

// pre-declare here as including causes circular include problems
class Event;

using std::shared_ptr;

//pre-declare so that there is not circular include
class TheMan;
class Ghost;

class TactileObject : public std::enable_shared_from_this<TactileObject>
{
public:
	virtual Event touch(shared_ptr<const TactileObject>) const;

	//in case the offspring doesn't specify the touching, do nothing in those
	virtual Event touch(shared_ptr<const TheMan>) const;
	virtual Event touch(shared_ptr<const Ghost>) const;

	virtual ~TactileObject() = 0;
};
