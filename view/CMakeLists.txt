cmake_minimum_required(VERSION 2.8.8)


# Обёртка для цветов
add_library_autolink(Color Color.cpp)

# Базопасный ncurses-экран
add_library_autolink(NcursesScreen NcursesScreen.cpp)

# Безопасное ncurses-окно
add_library_autolink(NcursesWindow NcursesWindow.cpp)

# vim: tw=78
