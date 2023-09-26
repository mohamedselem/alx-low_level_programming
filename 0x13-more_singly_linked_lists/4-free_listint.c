#include "lists.h"

/**
 * free_listint - frees a linked list from data
 * @head: listint_t list to be freed from data
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
	temp = head->next;
	free(head);
	head = temp;
	}
}

