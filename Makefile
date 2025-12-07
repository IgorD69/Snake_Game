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

TARGET    = $(BIN_DIR)/SnakeGame.out

SRC       = $(wildcard $(SRC_DIR)/*.cpp)
OBJ       = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# ======================================================
#                   RULAȚI ASTA NORMAL
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
#                   COMPILARE .cpp → .o
# ======================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "[CC]    $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ======================================================
#                     COMENZI UTILE
# ======================================================
.PHONY: run
run: $(TARGET)
	@echo "[RUN]  $(TARGET)"
	./$(TARGET)

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
