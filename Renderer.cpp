#include "Renderer.hpp"
#include "Position.hpp"
#include <iostream>

void Renderer::ClearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

void Renderer::DrawImage(Position topLeft, Position bottomRight, const Image& image) {
    for(const auto& line : image) {
        std::cout << line << std::endl;
    }
}
void Renderer::WriteText(Position position, const std::string& text) {
    std::cout << text;
}