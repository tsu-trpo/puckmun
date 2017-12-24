#include "objects/ExampleObject.h"

char ExampleObject::get_form()
{
	return ' ';
}
Color ExampleObject::get_bg_color()
{
	return Color::Yellow;
}
Color ExampleObject::get_body_color()
{
	return Color::Black;
}

MoveDirection ExampleObject::tick()
{
	return MoveDirection::Down;
}

GameObject& ExampleObject::demote()
{
	return *this;
}
GameObject& ExampleObject::promote()
{
	return *this;
}
