#include "errors/BasicMapLoader-errors.h"

FiletypeError::FiletypeError(const string& w)
	: std::logic_error(w)
{}

FiletypeError::FiletypeError(const char* w)
	: std::logic_error(w)
{}

IllFormedMapError::IllFormedMapError(const string& w)
	: std::logic_error(w)
{}

IllFormedMapError::IllFormedMapError(const char* w)
	: std::logic_error(w)
{}
