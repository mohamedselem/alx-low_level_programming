#include "lists.h"

/**
 * dlistint_len - function to returns the number of elements in
 * double linked list
 *
 * @h: head of the lists
 * Return: number of the nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int counts;

	counts = 0;

	if (h == NULL)
		return (counts);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		counts++;
		h = h->next;
	}

	return (counts);
}
