#include "objects/GameObject.h"

class Ghost: public GameObject
{	
	MoveDirection m_current;
public:
	Ghost();
	MoveDirection tick() const;
	Ghost & set_current(MoveDirection);
};
