# Compiler and flags
CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -std=c99

# Source files and object files
SRCS = main.c exec_cmd.c get_location.c exec_cd.c my_strcpy.c my_strcat.c my_strlen.c my_strdup.c my_getenv.c my_strncmp.c my_strcmp.c my_getline.c
OBJS = $(SRCS:.c=.o)
DEPS = main.h

# Executable name
EXEC = hsh

# Build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

# Build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)
