#pragma once

#include <iostream>

class Map {
   int width;
   int height;
public:
   Map(int width = 40, int height = 40);
   Map(const Map& other);
   int GetWidth() const;
   int GetHeight() const;

   Map operator = (const Map& other);
   bool operator == (const Map& other) const;
};

std::istream& operator >> (std::istream& in, Map& board);
std::ostream& operator << (std::ostream& out, const Map& board);
