#pragma once

#include "Player.hpp"

class Map{
    int witdh = 20;
    int height = 20;
    public:

    Map(int width = 20, int height = 20);
    int GetWidth() const;
    int GetHeight() const;
};
