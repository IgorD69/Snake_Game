/**
 * @brief Teste unitare pentru clasa Apple
 *
 * @project Snake Game
 * @author Igor Dodan
 * @date 2025
 *
 * Acest fișier conține teste unitare pentru verificarea funcționalității
 * clasei Apple utilizând Google Test Framework.
 */

#pragma once

// #include <cstdlib>
#include <iostream>
#include "Position.hpp"

class Apple {
   Position _position;
public:
   Apple();
   Apple(const Position& position);
   Apple(const Apple& other);
   Position GetPosition() const;


   Apple operator = (const Apple& other);
   bool operator == (const Apple& other) const;
};

std::istream& operator >> (std::istream& in, Apple& apple);
std::ostream& operator << (std::ostream& out, const Apple& apple);
