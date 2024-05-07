#include "search_algos.h"

/**
 * interpolation_search - func do Interpolation search to algorithm
 * @array: the Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not present
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t lower = 0, high = size - 1;
	size_t pos;
	double formulas;

	if (array == NULL)
		return (-1); /* Return -1 if the array is NULL */

	/* Interpolation search loop */
	while (lower <= high && value >= array[lower] && value <= array[high])
	{
		formulas = (((double)(high - lower) / (array[high] - array[lower]))
						* (value - array[lower]));
		/* Calculate the position using interpolation formulas */
		pos = (size_t)(lower + formulas);

		/* Print the checked value */
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		/* Check if value is found at the calculated position */
		if (array[pos] == value)
			return (pos); /* Return the index if the value is found */

		/* Adjust the search range based on the comparison with the value */
		if (array[pos] < value)
			lower = pos + 1;
		else
			high = pos - 1;
	}

	/* Print a message if the checked position is out of range */
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1); /* Return -1 if the value is not found in the array */
}
