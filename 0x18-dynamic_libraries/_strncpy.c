
#include "main.h"

/**
 * _strncpy - Copies n characters from one string to another.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n) {
    char *temp = dest;

    while (n-- && (*dest++ = *src++))
        ;

    while (n--)
        *dest++ = '\0';

    return temp;
}

