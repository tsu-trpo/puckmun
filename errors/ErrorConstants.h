#pragma once

//defines macros to be used for errors
#define STRINGIFY(x) STRINGIFY_MAGIC(x)
#define STRINGIFY_MAGIC(x) #x

#define ERR_HEADER "In file " __FILE__ " on line " STRINGIFY(__LINE__) ":\n    "
