cmake_minimum_required(VERSION 2.8.8)
project(control)

# Все типы событий
add_subdirectory(events)

# Главный цикл игры
add_library(EventLoop STATIC
	EventLoop.cpp
)

# Обёртка для видов событий
add_library(Event STATIC
	Event.cpp
)
