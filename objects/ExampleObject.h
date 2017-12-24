#pragma once

#include "objects/GameObject.h"

class ExampleObject : public GameObject
{
public:
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;

	GameObject& promote() override;
	GameObject& demote() override;

	MoveDirection tick() override;
};
