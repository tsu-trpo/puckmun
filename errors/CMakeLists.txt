cmake_minimum_required(VERSION 2.8.8)
project(objects)


# Библиотека с картой
add_library(BasicMapLoader-errors STATIC
	BasicMapLoader-errors.cpp
)
