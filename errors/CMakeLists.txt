cmake_minimum_required(VERSION 2.8.8)


# Ошибки загрузчика карты
add_library_autolink(BasicMapLoader-errors BasicMapLoader-errors.cpp)

# Ошибки ncurses
add_library_autolink(NcursesError NcursesError.cpp)

# vim: tw=78
