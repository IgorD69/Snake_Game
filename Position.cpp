#include "Position.hpp"
#include "iostream"

Position::Position(int _x, int _y) : x(_x), y(_y) {}

Position::Position(const Position &other) : x(other.x), y(other.y) {}

Position Position::operator=(const Position &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y;
}

std::istream& operator >> (std::istream& in, Position& point){
    int x, y;
    in >> x >> y;
    point = Position(x, y);
    return in;
}

std::ostream& operator << (std::ostream& out, const Position& point){
    out << point.x << " " << point.y;
    return out;
}
