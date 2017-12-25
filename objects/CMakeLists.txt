cmake_minimum_required(VERSION 2.8.8)
project(objects)


# Библиотека с картой
add_library_autolink(Map Map.cpp)

# Библиотека с AnimateObject
add_library_autolink(AnimateObject AnimateObject.cpp)
