#include "main.h"

/**
 * print_line - draws  straight line in the Terminal
 * @n: number of times the character _ couldd be printed
*/
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int o;

		for (o = 1; o <= n; o++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}

}
