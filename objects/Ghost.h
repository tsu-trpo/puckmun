#pragma once

#include "objects/GameObject.h"

class Ghost: public GameObject
           , public std::enable_shared_from_this<Ghost>
{	
	MoveDirection m_current;
public:
	Ghost();
	MoveDirection tick() override;
	Ghost & set_current(MoveDirection);
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;

	GameObject& promote() override;
	GameObject& demote() override;

	bool eats_points() const override;

	PhysicsEvents touch(const shared_ptr<TactileObject>&) override;
	PhysicsEvents touch(const shared_ptr<TheMan>&)        override;
	PhysicsEvents touch(const shared_ptr<Ghost>&)         override;
};
