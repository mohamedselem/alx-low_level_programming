#include "lists.h"

/**
 * free_dlistint - free  dlistint_t list.
 * @head: pointer to the head of the list
 * Return: NOthing
 **/
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	return;

	while (head->next)
	{
	head = head->next;
	free(head->prev);
	}
	free(head);
}
