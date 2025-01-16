# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Executable targets
TARGET = active_object
TEST_TARGET = test_runner

# Source files
SRC = src/active_object.c src/main.c
TEST_SRC = tests/test_active_object.c src/active_object.c tests/unity/unity.c

# Default target
all: $(TARGET)

# Application build
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Test build
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TEST_TARGET)

# Debugging rule to verify paths
debug:
	@echo "Application Source: $(SRC)"
	@echo "Test Source: $(TEST_SRC)"
