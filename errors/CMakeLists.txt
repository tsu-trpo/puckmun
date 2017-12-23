cmake_minimum_required(VERSION 2.8.8)
project(errors)


# Ошибки рендера
add_library(GameRender-errors STATIC
	GameRender-errors.cpp
)


# Ошибки загрузчика карты
add_library(BasicMapLoader-errors STATIC
	BasicMapLoader-errors.cpp
)
# vim: tw=78
