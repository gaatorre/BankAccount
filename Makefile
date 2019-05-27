# Compiler
CC = gcc
# Compilation flags
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99
CFLAGS += -D_BSD_SOURCE -D_DEFAULT_SOURCE
# Preprocessor directives
CPPFLAGS = -Iinclude
# Libraries
LDLIBS = -lm

# src and object directories
SRC_DIR = src
OBJ_DIR = obj

# The name of the executable
EXE = bank

# All the sources and objects
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Phony rules
# all   - Compile and link C files into executable
# clean - Remove all the object files and executable
# set   - Run the setup script
.Phony: all clean set

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Compile .c files and place them in the obj folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)
