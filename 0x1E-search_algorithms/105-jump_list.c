#include "search_algos.h"

/**
 * jump_list - searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @list: input list
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t indexer, k, m;
	listint_t *prev;
	if (list == NULL || size == 0)
		return (NULL);
	m = (size_t)sqrt((double)size);
	indexer = 0;
	k = 0;

	do {
		prev = list;
		k++;
		indexer = k * m;

		while (list->next && list->indexer < indexer)
			list = list->next;
		if (list->next == NULL && indexer != list->indexer)
			indexer = list->indexer;
		printf("Value checked at index [%d] = [%d]\n", (int)indexer, list->n);
	} while (indexer < size && list->next && list->n < value);

	
	printf("Value found between indexes [%d] and [%d]\n",
				(int)prev->indexer, (int)list->indexer);
	
	for (; prev && prev->indexer <= list->indexer; prev = prev->next)
	{
		
		printf("Value checked at index [%d] = [%d]\n", (int)prev->indexer, prev->n);

		if (prev->n == value) 
			return (prev);
	}
	return (NULL); 
}
