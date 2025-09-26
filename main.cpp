#include "Engine.hpp"
#include "iostream"

int main() {
    std::cout << "Welcome to Snake\n";
    Engine engine;
    engine.Init();
    engine.Run();
    return 0;
}
