#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 algorithm for hashing strings
 * @str: The string to hash
 *
 * Return: The computed hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	if (str == NULL)
		return (0);

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash);
}

