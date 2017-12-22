cmake_minimum_required(VERSION 2.8.8)
project(events)

# Просто разные ивенты

add_library(AddWall STATIC
	AddWall.cpp
)

add_library(Demote STATIC
	Demote.cpp
)

add_library(DestroyWall STATIC
	DestroyWall.cpp
)

add_library(EatPoint STATIC
	EatPoint.cpp
)

add_library(Move STATIC
	Move.cpp
)

add_library(Nothing STATIC
	Nothing.cpp
)

add_library(Promote STATIC
	Promote.cpp
)
