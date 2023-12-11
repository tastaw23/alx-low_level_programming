
#include "main.h"
#include <string.h>
/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be analyzed.
 * @accept: The string containing the characters to match.
 *
 * Return: The number of bytes in the initial segment of s which consist only
 * of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;

    while (*s && strchr(accept, *s++))
        count++;

    return count;
}

