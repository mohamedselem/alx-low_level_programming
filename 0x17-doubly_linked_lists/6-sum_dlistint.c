#include "lists.h"

/**
 * sum_dlistint - func to returns the sum of all the data
 * of a doubly linked list
 *
 * @head: the head of list
 * Return: the sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum1;

	sum1 = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			sum1 += head->n;
			head = head->next;
		}
	}

	return (sum1);
}
