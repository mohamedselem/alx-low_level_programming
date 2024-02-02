#include "hash_tables.h"

/**
 * hash_table_create - func Creates hash table.
 * @size: The size of array.
 *
 * Return: If an error happens  - NULL.
 *         Otherwise - a pointer to new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hit;
	unsigned long int z;

	hit = malloc(sizeof(hash_table_t));
	if (hit == NULL)
		return (NULL);

	hit->size = size;
	hit->array = malloc(sizeof(hash_node_t *) * size);
	if (hit->array == NULL)
		return (NULL);
	for (z = 0; z < size; z++)
		hit->array[z] = NULL;

	return (hit);
}
