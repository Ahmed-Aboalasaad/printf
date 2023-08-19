#include "main.h"
#include <stdlib.h>

/**
* print_binary - prints the given unsigned int in binary
* it prints negative numbers in 2's complement
*
* @n: the unsigned int number
* Return: the number of characters printed
*/
int print_binary(unsigned int n)
{
	unsigned int nCopy = n, digitCount = 0, digitCountCopy;
	char *binary;

	/* find #digits needed for binary represenation */
	while (nCopy > 0)
		nCopy /= 2, digitCount++;
	if (n == 0)
		digitCount = 1;

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
