# ======================================================
#           GoogleTest Build System - Snake Game
#======================================================

CXX        = g++
CXXFLAGS   = -std=c++17 -Wall -Wextra -O2

# GoogleTest
TEST_FLAGS = -lgtest -lgtest_main -pthread

# Raylib & alte librării folosite în joc
LDFLAGS    = -lraylib -lm -ldl -lpthread

# Directoare
TEST_DIR   = .
OBJ_DIR    = ../obj
SRC_DIR    = ..

# Teste (.cpp din tests/)
TEST_SRC   = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ   = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.test.o, $(TEST_SRC))

# Sursele jocului (fără main.cpp)
CORE_SRC   = $(wildcard $(SRC_DIR)/*.cpp)
CORE_SRC   := $(filter-out $(SRC_DIR)/main.cpp, $(CORE_SRC))
CORE_OBJ   = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CORE_SRC))

# Executabilul de test
TARGET     = ../bin/tests.out

# ======================================================
#                     BUILD TESTS
# ======================================================
all: dirs $(TARGET)
	@echo "======================================="
	@echo "  ✓ Teste compilate!"
	@echo "  Rulează testele cu: make run"
	@echo "======================================="

dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ../bin

$(TARGET): $(CORE_OBJ) $(TEST_OBJ)
	@echo "[LINK TESTS] $@"
	$(CXX) $(CXXFLAGS) $^ -o $@ $(TEST_FLAGS) $(LDFLAGS)

# ======================================================
#               COMPILARE TESTE & SURSE
# ======================================================

# Compilează fișierele din tests/
$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.cpp
	@echo "[CC TEST] $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilează sursele jocului (fără main)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "[CC SRC] $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ======================================================
#                       RUN & CLEAN
# ======================================================

run:
	./$(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.test.o
	rm -f $(TARGET)

clean_all:
	rm -f $(OBJ_DIR)/*.test.o
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)
