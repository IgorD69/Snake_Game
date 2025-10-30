#pragma once

#include <iostream>

enum class Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

std::ostream& operator<<(std::ostream& out, const Direction& direction);
