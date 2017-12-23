cmake_minimum_required(VERSION 2.8.8)
project(view)


# Ошибки рендера
add_library(GameRender-errors STATIC
	GameRender-errors.cpp
)

# vim: tw=78
