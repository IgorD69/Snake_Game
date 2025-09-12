#pragma once

class Renderer{
    void Init();
    void SetBackgroundColor(int r, int g, int b);
    void SetForgroundColor(int r, int g, int b);
    void ClearScreen();
    void PutText(int x, int y, const char* text);
    void PutBox();
    void Draw();
};
