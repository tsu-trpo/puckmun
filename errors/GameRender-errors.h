#pragma once

#include <stdexcept>

class ScreenLimit : public std::logic_error
{
public:
	ScreenLimit(const std::string&);
	ScreenLimit(const char*);
};
