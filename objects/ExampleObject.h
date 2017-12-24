#pragma once

#include "objects/GameObject.h"

class ExampleObject : public GameObject
{
public:
	char get_form() override;
	Color get_bg_color() override;
	Color get_body_color() override;

	GameObject& promote() override;
	GameObject& demote() override;

	MoveDirection tick() override;
};
