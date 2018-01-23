cmake_minimum_required(VERSION 2.8.8)


# Все типы команд
add_subdirectory(commands)

# Обёртка для команд
add_library_autolink(Command Command.cpp)

# Основной ввод с клавиатуры для чувака
add_library_autolink(TheManPlayerInput TheManPlayerInput.cpp)

# Основной ввод для призрака
add_library_autolink(GhostInput GhostInput.cpp)

# vim: tw=78
