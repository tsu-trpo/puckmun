#pragma once

#include <cstddef>

#include "control/MoveDirection.h"

// В этом файле описаны важные константы и типы, относящиеся к движению вещей

// Тип, хранящий частоту реакции объектов
typedef unsigned char PeriodT;

// Тип, хранящий время
typedef size_t TimeT;

// Значение стандартного направления
MoveDirection StandartDirection = MoveDirection::Down;

// vim: tw=78
