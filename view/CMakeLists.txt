cmake_minimum_required(VERSION 2.8.8)
project(view)


# Обёртка для цветов
add_library_autolink(Color Color.cpp)

# Базопасный ncurses-экран
add_library_autolink(NcursesScreen NcursesScreen.cpp)

# Безопасное ncurses-окно
add_library_autolink(NcursesWindow NcursesWindow.cpp)

# Главный рендер поля
add_library_autolink(GameRender GameRender.cpp)

# vim: tw=78
