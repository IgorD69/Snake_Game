#include "Direction.hpp"

std::ostream& operator<<(std::ostream& out, const Direction& direction){
    switch (direction)
    {
    case Direction::UP:
        out << "Top";
        break;
    case Direction::LEFT:
        out << "Left";
        break;
    case Direction::RIGHT:
        out << "Right";
        break;
    case Direction::DOWN:
        out << "Bottom";
        break;
    default:
        break;
    }
    return out;
}
