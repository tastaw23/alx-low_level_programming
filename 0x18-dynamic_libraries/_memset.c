
#include "main.h"

/**
 * _memset - Fills the first n bytes of memory with a constant byte.
 * @s: The memory area to fill.
 * @b: The constant byte.
 * @n: The number of bytes to fill.
 *
 * Return: A pointer to the filled memory area.
 */
char *_memset(char *s, char b, unsigned int n) {
    while (n--)
        *s++ = b;

    return s;
}

