# Snake Game

**Project:** Snake Game
**Author:** Dodan Igor
**Year:** 2025

---

## 📖 Project Description

Snake Game is a modern implementation of the classic Snake game, developed in C++ using the Raylib graphics library. The game offers a pleasant visual experience with colorful graphics and intuitive controls.

### Main Features:
- **Modern Graphics** - Rendering with Raylib, vibrant colors and smooth animations
- **Intuitive Controls** - Support for WASD and arrow keys
- **Score System** - Real-time progress tracking
- **Restart Mechanism** - Quick restart after game over
- **Modular Architecture** - Well-structured and easily extensible code

---

## 🎮 Game Rules

### Objective
The goal of the game is to control the snake to collect as many apples as possible, thus increasing your length and score. The game ends when the snake hits a wall or its own body.

### Controls
- **W** or **↑** - Move up
- **S** or **↓** - Move down
- **A** or **←** - Move left
- **D** or **→** - Move right
- **R** - Restart after game over
- **Q** or **ESC** - Exit game

### Game Mechanics

1. **Start**
   - Snake begins with length 1 in the center of the map
   - Moves automatically to the right
   - Apple is placed randomly on the map

2. **Collecting Apples**
   - When the snake reaches the apple, it is eaten
   - Snake grows by one segment
   - Score increases by 1 point
   - A new apple appears in a random position

3. **Movement**
   - Snake moves continuously in the current direction
   - Speed is constant (0.15 seconds between moves)
   - You can change direction anytime with control keys

4. **Collisions**
   - **With Walls** - Game ends if snake hits the map edge
   - **With Own Body** - Game ends if head hits another segment of the snake

5. **Game Over**
   - On collision, game pauses
   - "GAME OVER!" message appears
   - Press **R** to restart the game
   - Press **Q** or **ESC** to exit

### Scoring System
- Initial score: 0
- +1 point for each apple collected
- Score = snake length - 1
- Score is displayed continuously at the bottom of the screen

---

## 🔧 Dependencies

### Development Environment
- **Supported Operating Systems:**
  - Linux (Ubuntu, Debian, Fedora, Arch, etc.)
  - macOS (with Homebrew)
  - Windows (via WSL - Windows Subsystem for Linux)

### Compiler
- **g++** version 7.0 or newer
- Support for C++11 standard or higher
- Version check:
  ```bash
  g++ --version
  ```

### Main Libraries

#### 1. Raylib (Required)
Graphics library used for rendering, windows, and input.

**Install Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install libraylib-dev
```

**Install Fedora:**
```bash
sudo dnf install raylib-devel
```

**Install Arch Linux:**
```bash
sudo pacman -S raylib
```

**Install macOS (Homebrew):**
```bash
brew install raylib
```

**Compile from source (all platforms):**
```bash
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```

**Install macOS:**
```bash
brew install googletest
```

### Checking Dependencies

You can verify if all dependencies are installed using:
```bash
make check_deps
```

---

## 🛠️ Building the Application

### 1. Cloning the Repository

```bash
git clone https://github.com/username/Snake_Game.git
cd Snake_Game
```

### 2. Compiling the Game

#### Simple compilation:
```bash
make
```

This will generate the `snake_game` executable in the current directory.

#### Compile and run:
```bash
make run
```

### 3. Running the Game

After compilation, run the game with:
```bash
./snake_game
```

### 4. Cleaning Generated Files

To delete object files and executable:
```bash
make clean
```

For complete cleanup (including tests):
```bash
make clean_all
```

### 5. Complete Recompilation

To recompile everything from scratch:
```bash
make rebuild
```

---

## 🧪 Testing

The project includes unit tests for the main components.

### Compiling Tests

```bash
make tests
```

### Running Tests

**Run all tests:**
```bash
make run_tests
```

**Run with detailed output:**
```bash
make run_tests_verbose
```

**Run specific tests:**
```bash
make run_tests_filter FILTER=PositionTest.*
```

### Available Tests

- **test_position** - 30 tests for Position class
- **test_apple** - 23 tests for Apple class
- **test_map** - 27 tests for Map class

---

## 📁 Project Structure

```
Snake_Game/
├── main.cpp              # Application entry point
├── Engine.hpp/cpp        # Main game engine
├── Player.hpp/cpp        # Snake logic
├── Apple.hpp/cpp         # Apple logic
├── Map.hpp/cpp           # Map management
├── Position.hpp/cpp      # Structure for coordinates
├── Direction.hpp/cpp     # Enumeration for directions
├── AbstractListener.hpp  # Interface for input
├── CmdListener.hpp/cpp   # Terminal input
├── Abstract_Renderer.hpp # Interface for rendering
├── Renderer.hpp/cpp      # Raylib rendering
├── tests/                # Unit tests
│   ├── test_position.cpp
│   ├── test_apple.cpp
│   └── test_map.cpp
├── Makefile             # Build system
├── Doxyfile             # Doxygen configuration
└── README.md            # This file
```

---

## 📚 Documentation

### Generating Documentation

The project uses Doxygen for automatic documentation.

**Install Doxygen:**
```bash
# Ubuntu/Debian
sudo apt-get install doxygen

# Arch
sudo pacman -S doxygen

# macOS
brew install doxygen
```

**Generate documentation:**
```bash
make docs
```
or
```bash
doxygen Doxyfile
```

HTML documentation will be generated in `docs/html/`. Open `docs/html/index.html` in a browser to view it.

---

## 🎯 Useful Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Compile the game |
| `make run` | Compile and run the game |
| `make clean` | Delete compiled files |
| `make rebuild` | Clean and recompile everything |
| `make tests` | Compile unit tests |
| `make run_tests` | Run all tests |
| `make run_tests_verbose` | Run tests with detailed output |
| `make clean_tests` | Delete test files |
| `make clean_all` | Complete cleanup (game + tests) |
| `make check_deps` | Check installed dependencies |
| `make docs` | Generate Doxygen documentation |
| `make help` | Display help for commands |

---

### C++11 compilation error

**Solution:** Make sure you're using a recent compiler.
```bash
g++ --version  # Check version
# Should be 7.0+
```

---

## 🤝 Contributing

Contributions are welcome! For major changes:

1. Fork the repository
2. Create a branch for your feature (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 👤 Author

**Dodan Igor**  
---

## 📞 Contact and Support

For questions, issues, or suggestions:
- Open an issue on GitHub
- Contact the author via email
- Consult the Doxygen documentation

---

## 🎓 Additional Resources

- [Raylib Documentation](https://www.raylib.com/)
- [Doxygen Manual](https://www.doxygen.nl/manual/)
- [Google Test Documentation](https://google.github.io/googletest/)
- [C++ Reference](https://en.cppreference.com/)

---
