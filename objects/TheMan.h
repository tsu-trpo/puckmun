#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/GameObject.h"
#include "control/MoveDirection.h"

class TheMan: public GameObject
{	
	MoveDirection m_current;
	MoveDirection m_future;
private:
	MoveDirection tick() override;
	void set_current();
	void set_future(MoveDirection);
	MoveDirection get_current() const;
	MoveDirection get_future() const;
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;

	GameObject& promote() override;
	GameObject& demote() override;

	// updater commands
	friend class TheManSetCurrent;
	friend class TheManSetFuture;
	//input class
	friend class TheManPlayerInput;

public:
	TheMan();
};
	
