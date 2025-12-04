#pragma once
#include "Abstract_Renderer.hpp"
#include <raylib.h>

class Renderer : public AbstractRenderer {
private:
    int windowWidth;
    int windowHeight;
    int cellSize;
    Font font;

public:
    Renderer(int width = 800, int height = 600, int cellSize = 20);
    ~Renderer() override;

    void ClearScreen() override;
    void DrawImage(Position topLeft, Position bottomRight, const GameImage& image) override;  // Changed here
    void WriteText(Position position, const std::string& text) override;

    // Raylib-specific
    bool ShouldClose() const;
    void BeginDrawing();
    void EndDrawing();
};
