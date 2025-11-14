#include "Direction.hpp"

std::ostream& operator<<(std::ostream& out, const Direction& direction){
    out << ToString(direction);
    return out;
}

std::string ToString(const Direction& direction) {
    switch (direction)
    {
    case Direction::UP:
        return "UP";
    case Direction::DOWN:
        return "DOWN";
    case Direction::LEFT:
        return "LEFT";
    case Direction::RIGHT:
        return "RIGHT";
    default:
        return "UNKNOWN";
    }
}

char ToChar(const Direction& direction) {
    return static_cast<char>(direction);
}

Direction FromChar(char c) {
    switch (c) {
        case 'w': return Direction::UP;
        case 's': return Direction::DOWN;
        case 'a': return Direction::LEFT;
        case 'd': return Direction::RIGHT;
        default: throw std::invalid_argument("Invalid character for Direction");
    }
}