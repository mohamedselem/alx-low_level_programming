#include "main.h"

/**
 * get_bit - function can returns A value of bit at AN index in dec numbers
 * @n: the number will be searched for
 * @index: the index of bit
 *
 * Return: the value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
