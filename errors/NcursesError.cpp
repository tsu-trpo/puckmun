#include "errors/NcursesError.h"

int __ncurses_error__;

NcursesError::NcursesError(const string& what)
	: std::runtime_error(what)
{}
NcursesError::NcursesError(const char* what)
	: std::runtime_error(what)
{}
