#include "Player.hpp"
#include "Position.hpp"

Player::Player() {/* ... */}
Player::Player(const Position &_position) {/* ... */}
void Player::Move(Direction direction) {/* ... */}
int Player::GetSize() const {return 1;}
Position Player::GetPosition() const {return _segments[99];}
void Player::Eat(const Apple &apple) {/* ... */}
