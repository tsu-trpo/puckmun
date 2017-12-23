#include "errors/GameRender-errors.h"

ScreenError::ScreenError(const std::string& s)
	: std::logic_error (s)
{}

ScreenError::ScreenError(const char* s)
	: std::logic_error (s)
{}

BadMap::BadMap(const std::string& s)
	: std::logic_error (s)
{}

BadMap::BadMap(const char* s)
	: std::logic_error (s)
{}
