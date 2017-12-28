cmake_minimum_required(VERSION 2.8.8)


# Все типы событий
add_subdirectory(events)

# Главный цикл игры
add_library_autolink(EventLoop EventLoop.cpp)

# Взаимодействие объектов
add_library_autolink(Physics Physics.cpp)

# Обёртка для видов событий
add_library_autolink(Event Event.cpp)

# Взаимодействия разного рода объектов
add_library_autolink(Interactions Interactions.cpp)
