#!/bin/bash

# Compile all .c files in the current directory and create object files
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c *.c

# Create the dynamic library liball.so from all the object files
gcc -shared -o liball.so *.o

# Clean up: remove the object files
rm *.o

