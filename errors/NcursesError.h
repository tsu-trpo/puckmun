#pragma once

#include <stdexcept>
#include <string>

#include "error.h"

using std::string;

// defines macros to use ncurses functions: it raises errors returned as exceptions

extern int __ncurses_error__;

class NcursesError : public std::runtime_error
{
public:
	NcursesError(const string&);
	NcursesError(const char*);
};


#define CALL __ncurses_error__ =
#define RAISE ; if (__ncurses_error__ == ERR) { throw NcursesError(ERR_HEADER "error in ncurses routine");}
