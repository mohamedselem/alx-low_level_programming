#include "hash_tables.h"

/**
 * hash_table_get - func to retrieve the value associated with
 * a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key don't matched - NULL.
 *         else - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *nod;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	nod = ht->array[index];
	while (nod && strcmp(nod->key, key) != 0)
		nod = nod->next;

	return ((nod == NULL) ? NULL : nod->value);
}
