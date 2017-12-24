#include "errors/NcursesError.h"

NcursesError::NcursesError(const string& what)
	: std::runtime_error(what)
{}
NcursesError::NcursesError(const char* what)
	: std::runtime_error(what)
{}
