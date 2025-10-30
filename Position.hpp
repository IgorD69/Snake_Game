#pragma once

#include <iostream>

struct Position{
   int x;
   int y;

   Position(int _x = 0, int _y = 0);
   Position(const Position& other);

   Position operator = (const Position& other);
   bool operator == (const Position& other) const;
};

std::istream& operator >> (std::istream& in, Position& point);
std::ostream& operator << (std::ostream& out, const Position& point);
