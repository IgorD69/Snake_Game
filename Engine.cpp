// #include <iostream>
#include "Engine.hpp"
#include "Renderer.hpp"
#include "CmdListener.hpp"

#include <memory>
#include <thread>
#include <cctype>


Engine::Engine() {}
void Engine::Init() {
    map = Map(40, 20);
    player = Player(Position(map.GetWidth() / 2, map.GetHeight() / 2));
    apple = Apple(Position(5, 5));
}
void Engine::Run() {
    std::unique_ptr<AbstractRenderer> renderer(new Renderer());
    CmdListener cmdListener;

    auto direction = Direction::RIGHT;

    while (!IsFinished()) {
        renderer->ClearScreen();
        // Game loop logic would go here
        char key = tolower(cmdListener.OnKeyPress());
        std::cout << "Key pressed: " << key << std::endl;

        try {
            direction = FromChar(key);
        } catch (...) {
            if (key == 'q') {
                break;
            }
        }
        player.Move(direction); // Example movement
        Image image (map.GetHeight(), std::string(map.GetWidth(), '.'));
        image[apple.GetPosition().y][apple.GetPosition().x] = '@';

        for(int i = 0; i < player.GetSize(); ++i) {
            Position pos = player.GetSegments()[i];
            image[pos.y][pos.x] = 'O';
        }

        renderer->DrawImage({0,0}, {10,10}, image);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

bool Engine::IsFinished() {
    return false; // Placeholder implementation
}
