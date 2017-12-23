cmake_minimum_required(VERSION 2.8.8)
project(view)


# Обёртка для цветов
add_library(Color STATIC
	Color.cpp
)

# Обёртка для цветов
add_library(GameRender STATIC
	GameRender.cpp
)

# vim: tw=78
