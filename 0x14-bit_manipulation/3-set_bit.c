#include "main.h"

/**
 * set_bit - a funct can ets a bit at a given index to num 1
 * @n: pointer to the number that will be changed
 * @index: index of  bit to set to NUM 1
 *
 * Return: 1 reffer to success, -1 reffer to failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
