#pragma once

#include <iostream>
#include "Position.hpp"

class Apple {
   Position _position;
public:
   Apple();
   Apple(const Position& position);
   Apple(const Apple& other);
   Position GetPosition() const;

   Apple operator = (const Apple& other);
   bool operator == (const Apple& other) const;
};

std::istream& operator >> (std::istream& in, Apple& apple);
std::ostream& operator << (std::ostream& out, const Apple& apple);
