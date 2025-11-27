#pragma once

// #include "Abstract_Renderer.hpp"
#include "Position.hpp"


class Renderer{
    void Init();
    void SetBackgroundColor(int r, int g, int b);
    void SetForgroundColor(int r, int g, int b);
    void ClearScreen();
    void PutText(Position position, char *text);
    void PutBox(int x, int y, int witdh, int height);
    virtual void Draw(Position topLeft, Position bottomRight, char **image);
    virtual void WriteText(Position position, char* text);
};
