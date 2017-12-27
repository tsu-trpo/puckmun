#include "objects/GameObject.h"

class Ghost: public GameObject
{	
	MoveDirection m_current;
public:
	Ghost();
	MoveDirection tick() override;
	Ghost & set_current(MoveDirection);
};
