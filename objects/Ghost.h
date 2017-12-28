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

	Event touch(shared_ptr<const TactileObject>) const override;
	Event touch(shared_ptr<const TheMan>)        const override;
	Event touch(shared_ptr<const Ghost>)         const override;
};
