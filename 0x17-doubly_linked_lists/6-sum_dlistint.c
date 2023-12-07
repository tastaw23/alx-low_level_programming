#include "lists.h"

/**
 * sum_dlistint - Calculate sum of all data values in a doubly linked list
 * @head: Pointer to the head of the list
 * Return: Sum of all data values in the list, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}

