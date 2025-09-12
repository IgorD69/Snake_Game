#pragma once

#include "Positon.hpp"


class Apple {
   Position _position;
public:
   Apple();
   Apple(const Position& position);
   Position GetPosition() const;
};
