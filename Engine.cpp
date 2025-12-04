#include "Engine.hpp"
#include "Renderer.hpp"
#include <raylib.h>
#include <memory>
#include <cstdlib>
#include <ctime>

Engine::Engine() : gameOver(false) {}

void Engine::Init() {
    map = Map(40, 20);
    player = Player(Position(map.GetWidth() / 2, map.GetHeight() / 2));
    apple = Apple(Position(5, 5));
    gameOver = false;
    srand(time(NULL));
}

bool Engine::CheckCollision() {
    Position head = player.GetPosition();

    // Check wall collision
    if (head.x < 0 || head.x >= map.GetWidth() ||
        head.y < 0 || head.y >= map.GetHeight()) {
        return true;
    }

    // Check self collision (snake hits its own body)
    const auto& segments = player.GetSegments();
    for (size_t i = 1; i < segments.size(); ++i) {
        if (head == segments[i]) {
            return true;
        }
    }

    return false;
}

void Engine::Run() {
    std::unique_ptr<Renderer> renderer(new Renderer(800, 600, 20));
    Direction direction = Direction::RIGHT;

    float moveTimer = 0.0f;
    float moveInterval = 0.15f;

    while (!renderer->ShouldClose()) {
        // Input handling
        if (!gameOver) {
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) direction = Direction::UP;
            if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) direction = Direction::DOWN;
            if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) direction = Direction::LEFT;
            if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) direction = Direction::RIGHT;
        }

        if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_ESCAPE)) break;

        // Restart game on R key
        if (gameOver && IsKeyPressed(KEY_R)) {
            Init();
            direction = Direction::RIGHT;
        }

        // Update game logic with timing
        if (!gameOver) {
            moveTimer += GetFrameTime();
            if (moveTimer >= moveInterval) {
                moveTimer = 0.0f;
                player.Move(direction);

                // Check collisions
                if (CheckCollision()) {
                    gameOver = true;
                }

                // Check collision with apple
                if (!gameOver && player.GetPosition() == apple.GetPosition()) {
                    player.Eat(apple);

                    // Spawn new apple at random position
                    int newX = rand() % map.GetWidth();
                    int newY = rand() % map.GetHeight();
                    apple = Apple(Position(newX, newY));
                }
            }
        }

        // Render
        renderer->BeginDrawing();

        // Create game image
        GameImage image(map.GetHeight(), std::string(map.GetWidth(), '.'));

        // Draw border
        for (int x = 0; x < map.GetWidth(); ++x) {
            image[0][x] = '#';
            image[map.GetHeight() - 1][x] = '#';
        }
        for (int y = 0; y < map.GetHeight(); ++y) {
            image[y][0] = '#';
            image[y][map.GetWidth() - 1] = '#';
        }

        // Draw apple
        Position applePos = apple.GetPosition();
        if (applePos.y >= 0 && applePos.y < map.GetHeight() &&
            applePos.x >= 0 && applePos.x < map.GetWidth()) {
            image[applePos.y][applePos.x] = '@';
        }

        // Draw snake
        for (int i = 0; i < player.GetSize(); ++i) {
            Position pos = player.GetSegments()[i];
            if (pos.y >= 0 && pos.y < map.GetHeight() &&
                pos.x >= 0 && pos.x < map.GetWidth()) {
                image[pos.y][pos.x] = 'O';
            }
        }

        renderer->DrawImage({10, 10}, {0, 0}, image);

        // Display score and instructions
        std::string scoreText = "Score: " + std::to_string(player.GetSize() - 1);
        renderer->WriteText({10, 550}, scoreText + " | WASD/Arrows: move | Q/ESC: quit");

        // Display game over message
        if (gameOver) {
            renderer->WriteText({300, 300}, "GAME OVER!");
            renderer->WriteText({250, 330}, "Press R to restart");
        }

        renderer->EndDrawing();
    }
}

bool Engine::IsFinished() {
    return gameOver;
}
