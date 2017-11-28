cmake_minimum_required(VERSION 2.8.8)
project(objects)


# Библиотека с картой
add_library(Map STATIC
	Map.cpp
)

# Библиотека с AnimateObject
add_library(AnimateObject STATIC
	AnimateObject.cpp
)