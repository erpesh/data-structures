# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I.

# Source groups
LIST_SRC = $(wildcard list/*.c)
ARRAY_SRC = $(wildcard array/*.c)
HASHMAP_SRC = $(wildcard hashmap/*.c)

LIST_OBJ = $(LIST_SRC:.c=.o)
ARRAY_OBJ = $(ARRAY_SRC:.c=.o)
HASHMAP_OBJ = $(HASHMAP_SRC:.c=.o)

# Executable names
LIST_EXE = list_demo
ARRAY_EXE = array_demo
HASHMAP_EXE = hashmap_demo

# Default full build
SRC = main.c $(LIST_SRC) $(ARRAY_SRC) $(HASHMAP_SRC)
OBJ = $(SRC:.c=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Build individual component executables
list: $(LIST_OBJ) $(ARRAY_OBJ)
	$(CC) $(CFLAGS) $^ -o $(LIST_EXE)

array: $(ARRAY_OBJ)
	$(CC) $(CFLAGS) $^ -o $(ARRAY_EXE)

hashmap: $(HASHMAP_OBJ)
	$(CC) $(CFLAGS) $^ -o $(HASHMAP_EXE)

# Run commands for each component
list-run: list
	./$(LIST_EXE)

array-run: array
	./$(ARRAY_EXE)

hashmap-run: hashmap
	./$(HASHMAP_EXE)

# Object file rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up everything
clean:
	rm -f $(OBJ) list/*.o array/*.o hashmap/*.o \
		$(TARGET) $(LIST_EXE) $(ARRAY_EXE) $(HASHMAP_EXE)
