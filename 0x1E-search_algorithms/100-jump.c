#include "search_algos.h"

/**
 * jump_search - func do Jump search algorithm
 * @array: the Pointer to the first element of the array to search in
 * @size: the Number of elements in array
 * @value: the Value to search for
 * Return: the Index where value is located, or -1 if not present
 */

int jump_search(int *array, size_t size, int value)
{
	int block, block_size;
	int i = 0, hold = 0;

	if (array == NULL || size == 0) /* Check if the array is NULL */
		return (-1);
	/* Calculate the block size using square root of size */
	block = sqrt((int)size);
	block_size = block;

	/* Print the initial value checked */
	printf("Value checked array[%d] = [%d]\n", hold, array[hold]);

	/* Perform the jump search */
	while (array[block] <= value && block <= (int)size - 1)
	{
		/* Break if the value is found at the current block or initial index */
		if (array[i] == value || array[block] == value)
			break;
		hold = block; /* Update holder index and print the checked value */
		printf("Value checked array[%d] = [%d]\n", hold, array[block]);
		block = block + block_size; /* Move to the next block */
	}

	printf("Value found between indexes [%d] and [%d]\n", hold, block);
	while (hold <= block)
	{
		
		if (hold >= (int)size)
			return (-1);
		
		printf("Value checked array[%d] = [%d]\n", hold, array[hold]);

		if (array[hold] == value) 
			return (hold);
		hold++; 
	}

	return (-1); 
}
