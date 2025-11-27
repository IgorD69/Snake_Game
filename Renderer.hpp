#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


struct Position {
    int x;
    int y;
};

using Drawables = std::vector<sf::Drawable*>;

class Renderer {
private:
    sf::RenderWindow window;
public:
    Renderer(int width, int height, const std::string& title);

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    bool IsOpen() const;
    void ClearScreen();
    void Display();

    // --- Desenare și I/O ---
    bool PollEvent(sf::Event& event);
    void Draw(const Drawables& objects);
    void WriteText(Position position, const std::string& text, int size = 24);

    sf::RenderWindow& GetWindow();
};
