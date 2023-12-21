#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts a key/value pair into the sorted hash table.
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	current_node = ht->shead;

	while (current_node != NULL && strcmp(current_node->key, key) < 0)
		current_node = current_node->snext;

	if (current_node != NULL && strcmp(current_node->key, key) == 0)
	{
		free(current_node->value);
		current_node->value = strdup(value);
		return (1);
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->sprev = NULL;
	new_node->snext = NULL;

	if (current_node != NULL)
	{
		new_node->sprev = current_node->sprev;
		current_node->sprev = new_node;
	}
	else
	{
		new_node->sprev = ht->stail;
		ht->stail = new_node;
	}

	if (new_node->sprev != NULL)
		new_node->sprev->snext = new_node;
	else
		ht->shead = new_node;

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key in the sorted hash table.
 * @ht: The sorted hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	current_node = ht->shead;

	while (current_node != NULL && strcmp(current_node->key, key) < 0)
		current_node = current_node->snext;

	if (current_node != NULL && strcmp(current_node->key, key) == 0)
		return (current_node->value);

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");

	current_node = ht->shead;

	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node != NULL)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");

	current_node = ht->stail;

	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node != NULL)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current_node, *next_node;

	if (ht == NULL)
		return;

	current_node = ht->shead;

	while (current_node != NULL)
	{
		next_node = current_node->snext;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = next_node;
	}

	free(ht->array);
	free(ht);
}

