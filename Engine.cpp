#include "Engine.hpp"
#include "Renderer.hpp"
#include <raylib.h>
#include <memory>
#include <cctype>

Engine::Engine() {}

void Engine::Init() {
    map = Map(40, 20);
    player = Player(Position(map.GetWidth() / 2, map.GetHeight() / 2));
    apple = Apple(Position(5, 5));
}

void Engine::Run() {
    std::unique_ptr<Renderer> renderer(new Renderer(800, 600, 20));
    Direction direction = Direction::RIGHT;

    float moveTimer = 0.0f;
    float moveInterval = 0.15f; // Move every 150ms

    while (!IsFinished() && !renderer->ShouldClose()) {
        // Input handling
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) direction = Direction::UP;
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) direction = Direction::DOWN;
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) direction = Direction::LEFT;
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) direction = Direction::RIGHT;
        if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_ESCAPE)) break;

        // Update game logic with timing
        moveTimer += GetFrameTime();
        if (moveTimer >= moveInterval) {
            moveTimer = 0.0f;
            player.Move(direction);

            // Check collision with apple
            if (player.GetPosition() == apple.GetPosition()) {
                // TODO: Implement apple eating and respawn
            }
        }

        // Render
        renderer->BeginDrawing();

        // Create game image
        GameImage image(map.GetHeight(), std::string(map.GetWidth(), '.'));  // Changed here
        image[apple.GetPosition().y][apple.GetPosition().x] = '@';

        for (int i = 0; i < player.GetSize(); ++i) {
            Position pos = player.GetSegments()[i];
            if (pos.y >= 0 && pos.y < map.GetHeight() &&
                pos.x >= 0 && pos.x < map.GetWidth()) {
                image[pos.y][pos.x] = 'O';
            }
        }

        renderer->DrawImage({10, 10}, {0, 0}, image);
        renderer->WriteText({10, 550}, "WASD/Arrows to move, Q/ESC to quit");

        renderer->EndDrawing();
    }
}

bool Engine::IsFinished() {
    return false; // TODO: Implement game over logic
}
