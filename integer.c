#include "main.h"
#include <limits.h>

/**
 * int_pow - power function
 * @b: base
 * @p: power
 *
 * Return: the base to the power
 */
int int_pow(int b, int p)
{
	int tmp = b;

	if (p == 0)
		return (1);
	if (p == 1)
		return (b);
	while (p-- > 1)
		b *= tmp;

	return (b);
}

/**
 * print_int - Prints a number
 *
 * @args: the arguments list given to _printf()
 * @buffer: the buffer
 * Return: the number of digits printed
 */
int print_int(va_list args, char *buffer)
{
	int n = va_arg(args, int);
	int nCopy = n, digitCount = 0, digitCountCopy, extraDigit = '#', printed = 0;

	/* if n is the smallest int possible, take a digit in your pocket */
	if (n == INT_MIN) /* reason: avoiding overflow */
	{
		extraDigit = -1 * (n % 10);
		n /= 10;
	}
	/* handle the zero case */
	if (n == 0)
	{
		buffer_char('0', buffer);
		return (1);
	}
	/* handle negative values */
	if (n < 0)
	{
		buffer_char('-', buffer);
		printed++, n = -n;
		nCopy = n;
	}
	/* count the digits */
	for (; nCopy > 0; digitCount++)
		nCopy /= 10;
	/* print the number (the heart of this function) */
	digitCountCopy = digitCount;
	for (; digitCountCopy > 0; digitCountCopy--)
	{
		nCopy = n;
		nCopy /= int_pow(10, digitCountCopy - 1);
		buffer_char('0' + nCopy % 10, buffer);
	}
	printed += digitCount;
	if (extraDigit != '#') /* if I saved a digit in my pocket before */
	{
		buffer_char('0' + extraDigit, buffer);
		printed++;
	}
	return (printed);
}

/**
 * unsigned_int_pow - power function
 * @b: base
 * @p: power
 *
 * Return: the base to the power
 */
unsigned int unsigned_int_pow(unsigned int b, unsigned int p)
{
	int tmp = b;

	if (p == 0)
		return (1);
	if (p == 1)
		return (b);
	while (p-- > 1)
		b *= tmp;

	return (b);
}

/**
 * print_unsigned_int - prints an unsigned integer
 *
 * @args: the arguments list given to _printf()
 * @buffer: the buffer
 * Return: the number of digits printed
*/
int print_unsigned_int(va_list args, char *buffer)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int nCopy = n, digitCount = 0, digitCountCopy, printed = 0;

	/* handle the zero case */
	if (n == 0)
	{
		buffer_char('0', buffer);
		return (1);
	}
	/* count the digits */
	for (; nCopy > 0; digitCount++)
		nCopy /= 10;
	/* print the number (the heart of this function) */
	digitCountCopy = digitCount;
	for (; digitCountCopy > 0; digitCountCopy--)
	{
		nCopy = n;
		nCopy /= unsigned_int_pow(10, digitCountCopy - 1);
		buffer_char('0' + nCopy % 10, buffer);
	}
	printed += digitCount;
	return (printed);
}
