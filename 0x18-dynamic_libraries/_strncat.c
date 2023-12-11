

#include "main.h"

/**
 * _strncat - Concatenates n characters from one string to another.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The number of characters to concatenate.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n) {
    char *temp = dest;

    while (*dest)
        dest++;

    while (n-- && (*dest++ = *src++))
        ;

    return temp;
}

