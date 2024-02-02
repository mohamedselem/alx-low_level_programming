#include "hash_tables.h"

/**
 * key_index - func to Get the index at which a key or value.
 *      pair should stored in array of a hash table.
 * @key: key to get the index of.
 * @size: size of array of the hash table.
 *
 * Return: index of the key.
 * Description: Use the djb2 Algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
