# basic Makefile for building simple C/C++ projects.

# Phony targets
.PHONY: all clean

# Executable name
EXEC = main

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(EXEC)

# Rule to link the object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the build files
clean:
	rm -f $(OBJS) $(EXEC)