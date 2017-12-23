#include "errors/GameRender-errors.h"

ScreenOverflow::ScreenOverflow(const std::string& s)
	: std::logic_error (s)
{}

ScreenOverflow::ScreenOverflow(const char* s)
	: std::logic_error (s)
{}
