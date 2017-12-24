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

MoveDirection tick()
{
	return MoveDirection::Down;
}
