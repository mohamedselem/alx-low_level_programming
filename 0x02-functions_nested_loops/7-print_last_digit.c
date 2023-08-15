#include "main.h"

/**
 * print_last_digit - Print the last digits of  number
 * @n: the int for extract the last digit from
 * Return: Value of the last digit
*/
int print_last_digit(int n)
{
	int a;

	if (n < 0)
	n = -n;

	a = n % 10;

	if (a < 0)
		a = -a;

	_putchar(a + '0');

	return (a);
}
