#include "objects/GameObject.h"

class Ghost: public GameObject
{	
	MoveDirection m_current;
public:
	Ghost();
	MoveDirection tick() override;
	Ghost & set_current(MoveDirection);
	MoveDirection get_current() const;
	char get_form() const override;
	Color get_bg_color() const override;
	Color get_body_color() const override;

	GameObject& promote() override;
	GameObject& demote() override;

	bool eats_points() const override;
};
