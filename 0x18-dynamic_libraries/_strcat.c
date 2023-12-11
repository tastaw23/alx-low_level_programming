
#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src) {
    char *temp = dest;

    while (*dest)
        dest++;

    while ((*dest++ = *src++))
        ;

    return temp;
}

