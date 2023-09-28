#include "main.h"

/**
 * clear_bit - function can sets value of a given bit to NUM 0
 * @n: pointer of the number which will be changed
 * @index: index of the bit will be cleared
 *
 * Return: 1 reffer to success, -1 reffer for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
