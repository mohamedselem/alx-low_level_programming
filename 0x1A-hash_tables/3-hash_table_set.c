#include "hash_tables.h"

/**
 * hash_table_set - func to add || update an element in hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add.
 * @value: The value associated with the key.
 *
 * Return: Upon failure - 0.
 *         ELSE - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *vcopy;
	unsigned long int index, z;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	vcopy = strdup(value);
	if (vcopy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (z = index; ht->array[z]; z++)
	{
		if (strcmp(ht->array[z]->key, key) == 0)
		{
			free(ht->array[z]->value);
			ht->array[z]->value = vcopy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(vcopy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = vcopy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
