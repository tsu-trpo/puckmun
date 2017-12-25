#pragma once

#include <string>
#include <fstream>

#include "objects/Map.h"
#include "objects/MapConstants.h"
#include "objects/Block.h"

//load map from file
Map basic_load_map(const string&);

void print_map(const Map&);

// vim: tw=78
