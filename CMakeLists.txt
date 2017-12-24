cmake_minimum_required(VERSION 2.8.8)
project(puckmun)

# Включаем отладочную информацию и нужную версию стандарта
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1y")

# Добавляем максимальный уровень предупреждений (в gcc)
# и treating warnings as errors
if ( CMAKE_COMPILER_IS_GNUCC )
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
endif ( CMAKE_COMPILER_IS_GNUCC )


set(ALL_PROJECT_LIBRARIES "" CACHE STRING "" FORCE)

# Функция, добавляющая библиотеку и записывающая её имя в глобальную переменную
function(add_library_autolink lib_name lib_path)
	message(STATUS "adding library ${lib_name}")
	add_library(${lib_name} STATIC ${lib_path})
	set(ALL_PROJECT_LIBRARIES
	    "${ALL_PROJECT_LIBRARIES} ${lib_name}"
	    CACHE STRING "" FORCE
	)
endfunction(add_library_autolink)

# Добавляем включение всех файлов из поддиректорий
include_directories(${puckmun_SOURCE_DIR})


add_subdirectory(control)
add_subdirectory(objects)
add_subdirectory(view)

message(STATUS "libraries added: ${ALL_PROJECT_LIBRARIES}")
