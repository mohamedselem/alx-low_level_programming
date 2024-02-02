#include "hash_tables.h"

/**
 * hash_djb2 - func do Hash implementing the djb2 algorithm.
 * @str: The string to hash.
 *
 * Return: The calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int z;

	hash = 5381;
	while ((z = *str++))
		hash = ((hash << 5) + hash) + z;

	return (hash);
}
