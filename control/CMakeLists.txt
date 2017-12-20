cmake_minimum_required(VERSION 2.8.8)
project(control)


add_library(EventLoop STATIC
	EventLoop.cpp
)

add_library(Event STATIC
	Event.cpp
)
