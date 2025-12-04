#include "Renderer.hpp"
#include <raylib.h>

Renderer::Renderer(int width, int height, int cellSize)
    : windowWidth(width), windowHeight(height), cellSize(cellSize) {
    InitWindow(windowWidth, windowHeight, "Snake Game");
    SetTargetFPS(60);
    font = GetFontDefault();
}

Renderer::~Renderer() {
    CloseWindow();
}

void Renderer::ClearScreen() {
    // Raylib handles this in BeginDrawing/EndDrawing
}

void Renderer::BeginDrawing() {
    ::BeginDrawing();
    ClearBackground(BLACK);
}

void Renderer::EndDrawing() {
    ::EndDrawing();
}

bool Renderer::ShouldClose() const {
    return WindowShouldClose();
}

void Renderer::DrawImage(Position topLeft, Position bottomRight, const GameImage& image) {  // Changed here
    for (size_t y = 0; y < image.size(); ++y) {
        for (size_t x = 0; x < image[y].size(); ++x) {
            if (image[y][x] != '.') {
                Color color = WHITE;

                if (image[y][x] == 'O') {
                    color = GREEN; // Snake body
                } else if (image[y][x] == '@') {
                    color = RED;   // Apple
                }

                DrawRectangle(
                    topLeft.x + x * cellSize,
                    topLeft.y + y * cellSize,
                    cellSize - 2,
                    cellSize - 2,
                    color
                );
            }
        }
    }
}

void Renderer::WriteText(Position position, const std::string& text) {
    DrawText(text.c_str(), position.x, position.y, 20, WHITE);
}
