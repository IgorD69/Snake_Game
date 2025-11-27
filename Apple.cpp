// #include <vector>
#include "Apple.hpp"
#include "Position.hpp"

Apple::Apple() : _position(0, 0) {}

Apple::Apple(const Position &position) : _position(position) {}

Apple::Apple(const Apple &other) : _position(other.GetPosition()) {}

Position Apple::GetPosition() const
{
    return _position;
}

Apple Apple::operator = (const Apple& other){
    _position = other.GetPosition();
    return *this;
}
bool Apple::operator == (const Apple& other) const{
    return GetPosition() == other.GetPosition();
}

std::istream& operator >> (std::istream& in, Apple& apple){
    Position position;
    in >> position;
    apple = Apple(position);
    return in;
}

std::ostream& operator << (std::ostream& out, const Apple& apple){
    out << apple.GetPosition();
    return out;
}
