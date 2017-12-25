cmake_minimum_required(VERSION 2.8.8)
project(events)

# Просто разные ивенты

add_library_autolink(AddWall AddWall.cpp)

add_library_autolink(Demote Demote.cpp)

add_library_autolink(DestroyWall DestroyWall.cpp)

add_library_autolink(EatPoint EatPoint.cpp)

add_library_autolink(Move Move.cpp)

add_library_autolink(Nothing Nothing.cpp)

add_library_autolink(Promote Promote.cpp)
