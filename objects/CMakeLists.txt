cmake_minimum_required(VERSION 2.8.8)


# Библиотека с картой
add_library_autolink(Map Map.cpp)

# Библиотека с SpaceObject
add_library_autolink(SpaceObject SpaceObject.cpp)


# Библиотека с Ghost
add_library(Ghost STATIC
	Ghost.cpp
)

