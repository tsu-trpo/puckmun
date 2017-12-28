#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "objects/GameObject.h"
#include "control/MoveDirection.h"

class TheMan: public GameObject
{	
	MoveDirection m_current;
private:
	TheMan();
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
};
	
