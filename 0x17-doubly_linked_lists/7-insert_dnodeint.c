#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node with value at specific index.
 *
 * @h: Pointer to the head of the doubly linked list.
 * @idx: Index where the new node should be inserted. Indexing starts at 0.
 * @n: Value to be stored in the new node.
 *
 * Return: Pointer to the newly inserted node on success, or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i;

	new_node = malloc(sizeof(dlistint_t));
	if (!h || !new_node)
	{
		return (NULL);
	}

	new_node->n = n;

	if (idx == 0)
	{
		new_node->prev = NULL;
		new_node->next = *h;
		if (*h)
		{
			(*h)->prev = new_node;
		}
		*h = new_node;
		return (new_node);
	}

	for (i = 0; temp && i < idx - 1; ++i)
	{
		temp = temp->next;
	}

	if (!temp)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

