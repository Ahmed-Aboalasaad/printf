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
	unsigned int nCopy = n, digitCount = 0, digitCountCopy, i;
	char *binary;

	/* find #digits in binary represenation */
	while (nCopy > 0)
	{
		nCopy /= 2;
		digitCount++;
	}

	/* allocate an array to put 0/1 in it */
	binary = malloc(sizeof(*binary) * digitCount + 1);
	if (binary == NULL)
	{
		print_string("Failed to allocate memory for binary conversion");
		return (0);
	}
	binary[digitCount] = '\0';

	/* fill in the binary from right to left */
	for (digitCountCopy = digitCount; digitCountCopy > 0; digitCountCopy--)
	{
		binary[digitCountCopy - 1] = (n % 2) + '0';
		n /= 2;
	}

	print_string(binary);
	free(binary);
	return (digitCount);
}
