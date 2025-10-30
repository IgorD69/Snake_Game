#include "Map.hpp"


Map::Map(int width, int height) : width(width), height(height) {}

Map::Map(const Map &other) : width(other.GetWidth()), height(other.GetHeight()) {}

int Map::GetWidth() const
{
    return width;
}

int Map::GetHeight() const
{
    return height;
}

Map Map::operator=(const Map &other)
{
    width = other.GetWidth();
    height = other.GetHeight();
    return *this;
}

bool Map::operator==(const Map &other) const
{
    return GetWidth() == other.GetWidth() && GetHeight() == other.GetHeight();
}

std::istream &operator>>(std::istream &in, Map &board)
{
    int width, height;
    in >> width >> height;
    board = Map(width, height);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Map &board)
{
    out << board.GetWidth() << " " << board.GetHeight();
    return out;
}
