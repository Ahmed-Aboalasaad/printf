#include "main.h"
#include <stdlib.h>

/**
 * print_octal - prints an unsigned int in ocatal system
 *
 * @n: the unsigned int number
 * @buffer: the buffer
 * Return: number of digits printed
 */
int print_octal(unsigned int n, char *buffer)
{
	unsigned int nCopy = n, digitCount = 0, digitCountCopy;
	char *octal;

	/* find #digits needed for octal represenation */
	while (nCopy > 0)
		nCopy /= 8, digitCount++;
	if (n == 0)
		digitCount = 1;

	/* allocate an array to store octal representation in it */
	octal = malloc(sizeof(*octal) * digitCount + 1);
	if (octal == NULL)
		return (0);
	octal[digitCount] = '\0';

	/* fill in the octal string from right to left */
	for (digitCountCopy = digitCount; digitCountCopy > 0; digitCountCopy--)
	{
		octal[digitCountCopy - 1] = (n % 8) + '0';
		n /= 8;
	}

	print_string(octal, buffer);
	free(octal);
	return (digitCount);
}
