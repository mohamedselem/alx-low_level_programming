#include "lists.h"

/**
 * print_dlistint - prints all the elements of a node
 *
 *
 * @h: head of the lists
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int counts;

	counts = 0;

	if (h == NULL)
		return (counts);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		counts++;
		h = h->next;
	}

	return (counts);
}
