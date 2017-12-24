#pragma once

#include "objects/GameObject.h"

class ExampleObject : public GameObject
{
public:
	char get_form() override;
	Color get_bg_color() override;
	Color get_body_color() override;

	MoveDirection tick() override;
};
