#include "main.h"

/**
 * more_numbers - print more numbers 0 to 14
*/

void more_numbers(void)
{
	int i, k;

	for (i = 1; i <= 10; i++)
	{
		for (k = 0; k <= 14; k++)
		{
			if (k >= 10)
				_putchar('1');
			_putchar (k % 10 + '0');
		}
		_putchar('\n');
	}
}

