#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include <iostream>

sf::Font globalFont;

Renderer::Renderer(int width, int height, const std::string& title)
    // Conversie explicită de la int la unsigned int
    : window(sf::VideoMode(
        static_cast<unsigned int>(width),
        static_cast<unsigned int>(height)),
      title)
{
    if (!globalFont.loadFromFile("arial.ttf")) {
        std::cerr << "Eroare: Nu s-a putut încărca fontul 'arial.ttf' pentru text! Asigură-te că fișierul este prezent." << std::endl;
    }
}


bool Renderer::IsOpen() const {
    return window.isOpen();
}

void Renderer::ClearScreen() {
    window.clear(sf::Color::Black);
}

void Renderer::Display() {
    window.display();
}

bool Renderer::PollEvent(sf::Event& event) {
    return window.pollEvent(event);
}

void Renderer::Draw(const Drawables& objects) {
    for (sf::Drawable* drawable : objects) {
        if (drawable) {
            window.draw(*drawable);
        }
    }
}

void Renderer::WriteText(Position position, const std::string& text, int size) {
    sf::Text sfmlText;

    if (globalFont.getInfo().family != "") {
        sfmlText.setFont(globalFont);
    }

    sfmlText.setString(text);
    sfmlText.setCharacterSize(size);
    sfmlText.setFillColor(sf::Color::White);

    sfmlText.setPosition(static_cast<float>(position.x), static_cast<float>(position.y));

    window.draw(sfmlText);
}

sf::RenderWindow& Renderer::GetWindow() {
    return window;
}
