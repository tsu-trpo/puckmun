#pragma once

#include <cstddef>

#include "control/MoveDirection.h"

// В этом файле описаны важные константы и типы, относящиеся к движению вещей

// Тип, хранящий частоту реакции объектов
typedef unsigned char PeriodT;

// Максимальное значение периода
const PeriodT MaxPeriod = 120; // делится на 1, 2, 3, 4, 5, 6, 8, 10, 12

// Тип, хранящий время
typedef size_t TimeT;

// vim: tw=78
