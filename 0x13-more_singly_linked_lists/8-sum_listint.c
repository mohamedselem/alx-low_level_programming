#include "lists.h"

/**
 * sum_listint - function can do calc sum of the data in a listint_t list
 * @head: first node in the linked list will be entered
 *
 * Return: the result of sum
 */
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp = head;

while (temp)
{
sum += temp->n;
temp = temp->next;
}

return (sum);
}
