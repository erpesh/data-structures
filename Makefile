# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -I.

# Sources and Objects
SRC = main.c list/list.c array/array.c
OBJ = $(SRC:.c=.o)

# Executable name
TARGET = program

# Default rule
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)
