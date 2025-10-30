# Compiler
CC = gcc

# Compiler flags
# -Isrc tells gcc to look in the 'src' folder for headers
CFLAGS = -Wall -g -Isrc

# All .c source files to be compiled
SRCS = src/main.c src/match.c src/output.c src/parse_args.c src/process.c

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