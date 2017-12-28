#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/GameObject.h"
#include "control/MoveDirection.h"
#include "control/Event.h"

class TheMan: public GameObject
{	
	MoveDirection m_current;
private:
	MoveDirection tick() override;
	void set_current(MoveDirection);
	MoveDirection get_current() const;
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;

	GameObject& promote() override;
	GameObject& demote() override;

	// updater commands
	friend class TheManSetCurrent;
	//input class
	friend class TheManPlayerInput;

public:
	TheMan();
	bool eats_points() const override;
public:
	Event touch(shared_ptr<const TactileObject>) const override;
	Event touch(shared_ptr<const TheMan>)        const override;
	Event touch(shared_ptr<const Ghost>)         const override;
};
	
