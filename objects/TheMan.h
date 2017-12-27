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
	TheMan();
	MoveDirection tick() override;
	void set_current();
	void set_future(MoveDirection);
	MoveDirection get_current() const;
	MoveDirection get_future() const;
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;
};
	
