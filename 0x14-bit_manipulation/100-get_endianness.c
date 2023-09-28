#include "main.h"

/**
 * get_endianness - function can checks the endianness.
 * Return: 0 refeered for big, 1 reffered for little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
