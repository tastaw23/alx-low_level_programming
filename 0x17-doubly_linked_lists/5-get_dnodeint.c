#include "lists.h"

/**
 * get_dnodeint_at_index - Get the node at a specific index in a doubly linked list
 * @head: Pointer to the head of the list
 * @index: Index of the node to retrieve
 * Return: Pointer to the node at the specified index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	for (i = 0; current != NULL && i < index; i++)
	{
		current = current->next;
	}

	return (current);
}

