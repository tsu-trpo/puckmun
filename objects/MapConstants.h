#pragma once

#include <cstddef>
#include "objects/Block.h"

// В этом файле описаны важные константы и типы, относящиеся к положению
// вещей на карте

// Тип, хранящий координаты
typedef size_t Coordinate;

// Значения стандартных координат для разных вещей
Coordinate StandartX = 0;
Coordinate StandartY = 0;

// Значение стандартного блока
Block StandartBlock = Block::Space;

// vim: tw=78
