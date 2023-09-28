#include "main.h"

/**
 * flip_bits - function do count number of bits to change
 * to get from one number to another NUM
 * @n: the first NUM
 * @m: the second NUM
 *
 * Return: the number of bits that changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
