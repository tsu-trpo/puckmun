cmake_minimum_required(VERSION 2.8.8)
project(puckmun)

# Включаем отладочную информацию и нужную версию стандарта
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++1y")
# Добавляем максимальный уровень предупреждений (в gcc)
if ( CMAKE_COMPILER_IS_GNUCC )
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif ( CMAKE_COMPILER_IS_GNUCC )

# Добавляем включение всех файлов из поддиректорий
include_directories(${puckmun_SOURCE_DIR})


add_subdirectory(control)
add_subdirectory(objects)
add_subdirectory(view)
