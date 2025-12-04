#include "Renderer.hpp"
#include <iostream>

void Renderer::ClearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

void Renderer::DrawImage(Position topLeft, Position bottomRight, const Image& image) {
    for (size_t i = 0; i < image.size(); ++i) {
        std::cout << image[i] << '\n';
    }
    std::cout << std::flush;
}

void Renderer::WriteText(Position position, const std::string& text) {
    std::cout << "\033[" << position.y << ";" << position.x << "H" << text << std::flush;
}
