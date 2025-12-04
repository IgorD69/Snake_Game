# ======================================================
#               Snake Game - Build System
#               Autor: Igor Dodan • 2025
# ======================================================

CXX       = g++
CXXFLAGS  = -std=c++17 -Wall -Wextra -O2
LDFLAGS   = -lraylib -lm -lpthread -ldl

SRC_DIR   = .
OBJ_DIR   = obj
BIN_DIR   = bin
TEST_DIR  = tests

TARGET     = $(BIN_DIR)/Player.out
TEST_TARGET = $(BIN_DIR)/test_runner

SRC       = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC  = $(wildcard $(TEST_DIR)/*.cpp)

OBJ       = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
TEST_OBJ  = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC))

TEST_FLAGS = -lgtest -lgtest_main -pthread

# ======================================================
#                   RULEAȚI ASTA NORMAL
# ======================================================
.PHONY: all
all: dirs $(TARGET)
	@echo "======================================="
	@echo "  ✓ Build complet!"
	@echo "  Rulează jocul cu: make run"
	@echo "======================================="

# ======================================================
#              DIRECTOARE AUTOCREATE
# ======================================================
dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# ======================================================
#             LINK EXECUTABIL PRINCIPAL
# ======================================================
$(TARGET): $(OBJ)
	@echo "[LINK]  $@"
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# ======================================================
#                 LINK EXECUTABIL TESTE
# ======================================================
$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	@echo "[LINK]  (tests) $@"
	$(CXX) $(CXXFLAGS) $^ -o $@ $(TEST_FLAGS)

# ======================================================
#                   COMPILARE .cpp → .o
# ======================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "[CC]    $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo "[CC]    (test) $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ======================================================
#                     COMENZI UTILE
# ======================================================
.PHONY: run
run: $(TARGET)
	@echo "[RUN]  $(TARGET)"
	./$(TARGET)

.PHONY: tests
tests: $(TEST_TARGET)
	@echo "[RUN TESTS]"
	./$(TEST_TARGET)

# ======================================================
#                      CLEAN
# ======================================================
.PHONY: clean
clean:
	@echo "[CLEAN]"
	rm -rf $(OBJ_DIR)/*.o

.PHONY: clean_all
clean_all:
	@echo "[CLEAN ALL]"
	rm -rf $(OBJ_DIR) $(BIN_DIR)

