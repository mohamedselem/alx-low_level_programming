#include "hash_tables.h"

/**
 * hash_table_print - func to Print a hash table.
 * @ht: pointer to hash table to print.
 *
 * Description: Key or value pairs are printed in the order
 * appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nod;
	unsigned long int z;
	unsigned char comm_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (z = 0; z < ht->size; z++)
	{
		if (ht->array[z] != NULL)
		{
			if (comm_flag == 1)
				printf(", ");

			nod = ht->array[z];
			while (nod != NULL)
			{
				printf("'%s': '%s'", nod->key, nod->value);
				nod = nod->next;
				if (nod != NULL)
					printf(", ");
			}
			comm_flag = 1;
		}
	}
	printf("}\n");
}
