cmake_minimum_required(VERSION 2.8.8)


# Все типы команд
add_subdirectory(commands)

# Обёртка для команд
add_library_autolink(Command Command.cpp)

# vim: tw=78
