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
	MoveDirection m_future;
	// whether he can eat ghosts
	bool m_promoted = false;
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
	bool eats_points() const override;
public:
	Event touch(shared_ptr<const TactileObject>) const override;
	Event touch(shared_ptr<const TheMan>)        const override;
	Event touch(shared_ptr<const Ghost>)         const override;

	bool get_promoted() const;

	GameObject& promote() override;
	GameObject& demote() override;
};
	
