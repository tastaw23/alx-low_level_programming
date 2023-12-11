
#include "main.h"

/**
 * _strcpy - Copies a string to another.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src) {
    char *temp = dest;

    while ((*dest++ = *src++))
        ;

    return temp;
}

