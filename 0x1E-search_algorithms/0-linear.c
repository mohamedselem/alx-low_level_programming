#include "search_algos.h"
#include <stddef.h>
#include <stdio.h>

/**
 * linear_search - func do linear search algorithm
 * @array: array of ints
 * @size: size of array
 * @value: value to search for
 * Return: position or -1 if not found
 *
 */

int linear_search(int *array, size_t size, int value)
{
	size_t z;

	if (array == NULL)
		return (-1); /* Return -1 if the array is NULL */

	for (z = 0; z < size; ++z)
	{
		printf("Value checked array[%lu] = [%d]\n", z, array[z]);

		if (array[z] == value)
			return (z); /* Return the index if the value is found */
	}
	return (-1); /* Return -1 if the value is not found in the array */
}
