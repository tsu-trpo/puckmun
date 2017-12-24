#pragma once

#include <stdexcept>

class ScreenError : public std::logic_error
{
public:
	ScreenError(const std::string&);
	ScreenError(const char*);
};

class BadMap : public std::logic_error
{
public:
	BadMap(const std::string&);
	BadMap(const char*);
};