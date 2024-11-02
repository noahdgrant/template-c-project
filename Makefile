# Variable declaratio# Variable declaration
CC = gcc
CFLAGS = -g -Wall -Wextra
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = $(BIN_DIR)/main

# Default build
all: $(TARGET)

# Release build
release: CFLAGS = -Wall -Wextra -O2 -DNDEBUG
release: clean
release: $(TARGET)

# Debug build
debug: CFLAGS = -g -Wall -Wextra -DDEBUG
debug: clean
debug: $(TARGET)

# Create binary files and object files
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Additional build commands
clean:
	$(RM) -r $(BIN_DIR)/* $(OBJ_DIR)/*

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  release  - Build the project in release mode"
	@echo "  debug    - Build the project in debug mode"
	@echo "  run      - Run the compiled program"
	@echo "  clean    - Remove all build files"
	@echo "  help     - Display this help message"

.PHONY: all release debug run clean help
