CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -O0
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = deakfish

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)