#include "Player.hpp"
#include "Position.hpp"

Player::Player() {/* ... */}
Player::Player(const Position &_position): _segments(1, _position) {/* ... */}

void Player::Move(Direction direction) {
    // Calculate new head position
    Position head = _segments[0];
    switch(direction) {
        case Direction::UP:    head.y -= 1; break;
        case Direction::DOWN:  head.y += 1; break;
        case Direction::LEFT:  head.x -= 1; break;
        case Direction::RIGHT: head.x += 1; break;
    }

    // Add new head at the front
    _segments.insert(_segments.begin(), head);

    // Remove tail (will be skipped if snake just ate)
    _segments.pop_back();
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

void Player::Eat(const Apple &apple) {
    // Add a new segment at the tail position (it will extend on next move)
    Position tail = _segments.back();
    _segments.push_back(tail);
}
