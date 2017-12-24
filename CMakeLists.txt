cmake_minimum_required(VERSION 2.6)
project(puckmun)

# и магическим образом все модули подгружаются
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "./cmake")

# Включаем отладочную информацию и нужную версию стандарта
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1y")

# Добавляем максимальный уровень предупреждений (в gcc)
# и treating warnings as errors
if ( CMAKE_COMPILER_IS_GNUCC )
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif ( CMAKE_COMPILER_IS_GNUCC )


# Добавляем ncurses
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(ALL_PROJECT_LIBRARIES "" CACHE STRING "" FORCE)

# Функция, добавляющая библиотеку и записывающая её имя в глобальную переменную
function(add_library_autolink lib_name lib_path)
	message(STATUS "adding library ${lib_name}")
	add_library(${lib_name} STATIC ${lib_path})

	if("${ALL_PROJECT_LIBRARIES}" STREQUAL "")
		set(ALL_PROJECT_LIBRARIES "${lib_name}" CACHE STRING "" FORCE)
	else()
		set(ALL_PROJECT_LIBRARIES
			"${ALL_PROJECT_LIBRARIES}" "${lib_name}"
			CACHE STRING "" FORCE
		)
	endif()
endfunction(add_library_autolink)

# Добавляем включение всех файлов из поддиректорий
include_directories(${puckmun_SOURCE_DIR})


add_subdirectory(control)
add_subdirectory(objects)
add_subdirectory(view)
add_subdirectory(errors)


add_executable(main main.cpp)
target_link_libraries(main ${ALL_PROJECT_LIBRARIES} ${ALL_PROJECT_LIBRARIES} ${CURSES_LIBRARY})


add_executable(ncurses_test ncurses_test.cpp)
target_link_libraries(ncurses_test ${CURSES_LIBRARY})

# vim: tw=78
