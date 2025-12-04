#pragma once

#include "Map.hpp"
#include "Apple.hpp"
#include "Player.hpp"
#include "Direction.hpp"

class Engine {
    Map map;
    Player player;
    Apple apple;
    bool gameOver;  // Add this
public:
    Engine();
    void Init();
    void Run();
    bool IsFinished();
    bool CheckCollision();  // Add this
};
