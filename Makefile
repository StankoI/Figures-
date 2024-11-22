# Компилатор и флагове
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -I/path/to/doctest

# Имена на файловете
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

# Списък с файлове
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Файлове за тестовете (без main.cpp)
TEST_SRCS = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
TEST_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))

# Целеви файлове
TARGET = $(BIN_DIR)/program
TEST_TARGET = $(BIN_DIR)/test_runner

# Основни цели
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Цел за тестовете (компилира тестовете, включва Doctest и линква)
$(TEST_TARGET): $(OBJS) $(TEST_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ -ldoctest

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Създаване на директории
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Чистене на генерирани файлове
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Рестартиране на проекта
rebuild: clean all

# Стартиране на тестовете
test: $(TEST_TARGET)
	@echo "=== Стартиране на тестовете ==="
	./$(TEST_TARGET)

# Помощ
help:
	@echo "Използвай make [опция], където опция може да бъде:"
	@echo "  all      - Компилира проекта"
	@echo "  test     - Компилира и стартира тестовете"
	@echo "  clean    - Изчиства компилираните файлове"
	@echo "  rebuild  - Рестартира проекта (clean + all)"
	@echo "  help     - Показва това съобщение"

