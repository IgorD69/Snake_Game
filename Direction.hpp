#pragma once

#include <iostream>

enum class Direction: char{
    UP      = 'w',
    DOWN    = 's',
    LEFT    = 'a',
    RIGHT   = 'd'
};

std::string ToString(const Direction& direction);
char ToChar(const Direction& direction);
Direction FromChar(char c);

std::ostream& operator<<(std::ostream& out, const Direction& direction);
