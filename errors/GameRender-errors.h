#pragma once

#include <stdexcept>

class ScreenOverflow : public std::logic_error
{
public:
	ScreenOverflow(const std::string&);
	ScreenOverflow(const char*);
};
