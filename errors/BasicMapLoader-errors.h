#pragma once

#include <stdexcept>
#include <string>

using std::string;

class FiletypeError : public std::logic_error
{
public:
	explicit FiletypeError(const string& what_arg);
	explicit FiletypeError(const char* what_arg);
};

class IllFormedMapError : public std::logic_error
{
public:
	explicit IllFormedMapError(const string& what_arg);
	explicit IllFormedMapError(const char* what_arg);
};
