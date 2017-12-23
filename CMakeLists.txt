cmake_minimum_required(VERSION 2.8.8)
project(puckmun)

# Включаем отладочную информацию и нужную версию стандарта
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1y")

# Добавляем максимальный уровень предупреждений (в gcc)
# и treating warnings as errors
if ( CMAKE_COMPILER_IS_GNUCC )
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
endif ( CMAKE_COMPILER_IS_GNUCC )


# Добавляем включение всех файлов из поддиректорий
include_directories(${puckmun_SOURCE_DIR})


# Добавляем ncurses
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Modules/")
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


add_subdirectory(control)
add_subdirectory(objects)
add_subdirectory(view)
add_subdirectory(errors)


add_executable(main main.cpp)
target_link_libraries(main Map MapLoader BasicMapLoader-errors Map GameRender
	GameRender-errors ${CURSES_LIBRARY})


add_executable(ncurses_test ncurses_test.cpp)
target_link_libraries(ncurses_test ${CURSES_LIBRARY})
