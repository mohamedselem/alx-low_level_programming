#include "lists.h"

/**
 * free_listint2 - frees a linked list from data
 * @head: pointer to listint_t list will freed
 */
void free_listint2(listint_t **head)
{
listint_t *temp;

if (head == NULL)
return;

while (*head)
{
temp = (*head)->next;
free(*head);
*head = temp;
}

*head = NULL;
}
