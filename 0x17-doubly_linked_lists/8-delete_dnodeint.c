#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node specific index in doubly linked list
 * @head: Pointer to the pointer to the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	if (current == NULL)
		return (-1);

	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev != NULL)
		current->prev->next = current->next;

	free(current);

	return (1);
}

