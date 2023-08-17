#include <stdio.h>
#include <math.h>

/**
 * main - finds then prints the largest prime factor of the number 612852475143
 * followed by a new line
 * Return: Always 0 (Success)
*/
int main(void)
{
	long int m;
	long int max;
	long int i;

	m = 612852475143;
	max = -1;

	while (m % 2 == 0)
	{
		max = 2;
		m /= 2;
	}

	for (i = 3; i <= sqrt(n); i = i + 2)
	{
		while (m % i == 0)
		{
			max = i;
			m = m / i;
		}
	}

	if (m > 2)
		max = m;

	printf("%ld\n", max);

	return (0);
}
