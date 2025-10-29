# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# All .c source files to be compiled
SRCS = main.c

# The name of the final program
TARGET = grep-clone-demo

# Default rule
all: $(TARGET)

# Rule to link the final program
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean up
clean:
	rm -f $(TARGET)