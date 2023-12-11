#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: On success, the character written is returned; otherwise, -1 is returned.
 */
int _putchar(char c) {
    return write(1, &c, 1);
}

