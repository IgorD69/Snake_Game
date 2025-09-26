#pragma once
#include "Position.hpp"


class Apple {
    Apple();
    Position _position;
public:
   Apple(const Position& position);
   Position GetPosition() const;
};
