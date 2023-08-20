#include "main.h"
#include <stdlib.h>

/**
 * print_hex - prints the given unsigned int in hexadecimal
 *
 * @n: the unsigned int number
 * @capital: would you like to capitalize letters ?
 * @buffer: the buffer
 * Return: number of characters printed
 */
int print_hex(unsigned int n, char capital, char *buffer)
{
	unsigned int nCopy = n, digitCount = 0, digitCountCopy;
	char *hex;
	char c = capital ? 'A' : 'a';

	/* find #digits needed for binary represenation */
	while (nCopy > 0)
		nCopy /= 16, digitCount++;
	if (n == 0)
		digitCount = 1;

	/* allocate an array to put 0/1 in it */
	hex = malloc(sizeof(*hex) * digitCount + 1);
	if (hex == NULL)
		return (0);
	hex[digitCount] = '\0';

	/* fill in the binary from right to left */
	for (digitCountCopy = digitCount; digitCountCopy > 0; digitCountCopy--)
	{
		/* This function differs from others number systems in this line: */
		hex[digitCountCopy - 1] = n % 16 + ((n % 16 > 9) ? c - 10 : '0');
		n /= 16;
	}

	print_string(hex, buffer);
	free(hex);
	return (digitCount);
}
