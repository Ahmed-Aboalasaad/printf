#include "main.h"
#include <stdlib.h>

/**
 * print_address - prints and address
 *
 * @p: the address
 * @buffer: the buffer
 * Return: the number of characters printed
 */
int print_address(unsigned long int p, char *buffer)
{
	unsigned long int pCopy = p, digitCount = 0, digitCountCopy;
	char *address;

	/* find #digits needed for octal represenation */
	while (pCopy > 0)
		pCopy /= 16, digitCount++;
	if (p == 0)
		digitCount = 1;

	/* allocate an array to put 0/1 in it */
	address = malloc(sizeof(*address) * digitCount + 1);
	if (address == NULL)
		return (0);
	address[digitCount] = '\0';

	/* fill in the address string from right to left */
	add_to_buffer('0', buffer);
	add_to_buffer('x', buffer);
	for (digitCountCopy = digitCount; digitCountCopy > 0; digitCountCopy--)
	{
		address[digitCountCopy - 1] = p % 16 + ((p % 16 > 9) ? 'a' - 10 : '0');
		p /= 16;
	}

	print_string(address, buffer);
	free(address);
	return (digitCount + 2);
}
