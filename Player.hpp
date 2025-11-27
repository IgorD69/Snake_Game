#pragma once
#include "Apple.hpp"
#include "Position.hpp"
#include "Direction.hpp"

#include <vector>

class Player {
   std::vector<Position> _segments;
public:
   Player();
   Player(const Position& _position);
   void Move(Direction direction);
   int GetSize() const;
   Position GetPosition() const;

   std::vector<Position> GetSegments() const;
   void Eat(const Apple& apple);
};
