cmake_minimum_required(VERSION 2.8.8)


# Все типы команд
add_subdirectory(commands)

# Обёртка для команд
add_library_autolink(Command Command.cpp)

# Ввод с клавиатуры для чувака
add_library_autolink(TheManPlayerInput TheManPlayerInput.cpp)

# vim: tw=78
