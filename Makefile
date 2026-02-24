CC = cc
CFLAGS = -Wall -Wextra -Wpedantic -g -fsanitize=address
INCLUDES = -Iinclude

SRC = src/main.c src/tasklist.c
TARGET = taskbox

all:
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)