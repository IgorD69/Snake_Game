#include "Player.hpp"
#include "Position.hpp"

Player::Player() {/* ... */}
Player::Player(const Position &_position): _segments(1, _position) {/* ... */}

void Player::Move(Direction direction) {
    // Example movement logic
    Position head = _segments[0];
    switch(direction) {
        case Direction::UP:    head.y -= 1; break;
        case Direction::DOWN:  head.y += 1; break;
        case Direction::LEFT:  head.x -= 1; break;
        case Direction::RIGHT: head.x += 1; break;
    }
    // Move segments
    for (auto i = _segments.size() - 1; i > 0; --i) {
        _segments[i] = _segments[i - 1];
    }
    _segments[0] = head;
}
int Player::GetSize() const {
    return static_cast<int>(_segments.size());
}

Position Player::GetPosition() const {
    return _segments[0];
}

std::vector<Position> Player::GetSegments() const {
    return _segments;
}

void Player::Eat(const Apple &apple) {/* ... */}
