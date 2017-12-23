#include "errors/GameRender-errors.h"

ScreenLimit::ScreenLimit(const std::string& s)
	: std::logic_error (s)
{}

ScreenLimit::ScreenLimit(const char* s)
	: std::logic_error (s)
{}
