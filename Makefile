CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

TARGET = active_object
SRC = src/active_object.c src/main.c
TEST_SRC = test/test_active_object.c src/active_object.c test/unity/unity.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) test_runner

test: test_runner
	./test_runner

test_runner: $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all clean test
