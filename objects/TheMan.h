#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/GameObject.h"
#include "control/MoveDirection.h"
#include "control/Event.h"

class TheMan: public GameObject
            , public std::enable_shared_from_this<TheMan>
{	
	MoveDirection m_current;
	// whether he can eat ghosts
	bool m_promoted = false;
	// looks of object
	Color m_bg_color;
	Color m_fg_color;
private:
	MoveDirection tick() override;
	void set_current(MoveDirection);
	MoveDirection get_current() const;
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;

	// updater commands
	friend class TheManSetCurrent;
	//input class
	friend class TheManPlayerInput;

public:
	TheMan();
	bool eats_points() const override;
public:
	PhysicsEvents touch(const shared_ptr<TactileObject>&) override;
	PhysicsEvents touch(const shared_ptr<TheMan>&)        override;
	PhysicsEvents touch(const shared_ptr<Ghost>&)         override;

	bool get_promoted() const;

	GameObject& promote() override;
	GameObject& demote() override;
};
	
