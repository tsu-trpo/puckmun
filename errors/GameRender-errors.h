#pragma once

#include <stdexcept>

class ScreenError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class BadMap : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class BadPosition : public std::runtime_error
{
public:
	ScreenError(const char*);
};
