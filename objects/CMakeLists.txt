cmake_minimum_required(VERSION 2.8.8)

# Библиотека с призраком
add_library_autolink(Ghost Ghost.cpp)

# Библиотека с TheMan
add_library_autolink(TheMan TheMan.cpp)

# Библиотека с картой
add_library_autolink(Map Map.cpp)

# Библиотека с загрузчиком
add_library_autolink(MapLoader MapLoader.cpp)

# Библиотека с SpaceObject
add_library_autolink(SpaceObject SpaceObject.cpp)

# Библиотека с AnimateObject
add_library_autolink(AnimateObject AnimateObject.cpp)

add_library_autolink(ExampleObject ExampleObject.cpp)

# Библиотека с интерфейсом взаимодействия
add_library_autolink(TactileObject TactileObject.cpp)

