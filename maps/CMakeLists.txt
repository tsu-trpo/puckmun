cmake_minimum_required(VERSION 2.6.0)

# Ничего не делать если собираю в папку проекта
if(NOT "${CMAKE_BINARY_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}")
	# удаляем старые ресурсы в папке сборки
	file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/maps")
	# копируем ресурсы в папку сборки
	file(COPY "${PROJECT_SOURCE_DIR}/maps" DESTINATION "${CMAKE_BINARY_DIR}")
endif()
