#include "main.h"
#include <stdlib.h>

/**
* print_binary - prints the given unsigned int in binary
* it can be easier with a stack but we're not allowed
* to use it yet
* 
* @n: the unsigned int number
* Return: the number of characters printed
*/
int print_binary(unsigned int n)
{
	unsigned int copy = n, digitCount = 0, i;
	char* binary;

	/* find #digits in binary represenation */
	while (copy > 0)
	{
		copy /= 2;
		digitCount++;
	}

	/* allocate an array to put 0/1 in it */
	binary = malloc(sizeof(char) * (digitCount + 1));

	if (binary == NULL)
		_putchar('#');

	/* fill in the binary from right to left */
	copy = digitCount;
	for (; copy > 0; copy--)
	{
		binary[copy - 1] = (n % 2) + 48;
		n /= 2;
	}
	binary[digitCount] = '\0';

	/* print in binary */
	for (i = 0; binary[i]; i++)
		_putchar(binary[i]);

	free(binary);
	return (digitCount);
}
