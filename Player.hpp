#pragma once
#include "Apple.hpp"
#include "Position.hpp"
#include "Direction.hpp"

class Player {
   Position _segments[100];
   int _nr_segments;
public:
    Player();
   Player(const Position& _position);
   void Move(Direction direction);
   int GetSize() const;
   Position GetPosition() const;
   void Eat(const Apple& apple);
};
