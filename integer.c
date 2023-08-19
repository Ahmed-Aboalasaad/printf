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
 * @n: the number to be printed
 * Return: the number of digits printed
 */
int print_int(int n)
{
	int nCopy = n, digitCount = 0, digitCountCopy, extraDigit = '#', printed = 0;

	/* if n is the smallest int possible, take a digit in your pocket */
	/* reason: when we make the number positive, it overflows */
	if (n == INT_MIN)
	{
		extraDigit = -1 * (n % 10);
		n /= 10;
	}
	/* handle the zero case */
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	/* handle negative values */
	if (n < 0)
	{
		_putchar('-');
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
		_putchar('0' + nCopy % 10);
	}
	printed += digitCount;
	if (extraDigit != '#') /* if I saved a digit in my pocket before */
	{
		_putchar('0' + extraDigit);
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
 * @n: the unsigned integer
 * Return: the number of digits printed
*/
int print_unsigned_int(unsigned int n)
{
	unsigned int nCopy = n, digitCount = 0, digitCountCopy, printed = 0;

	/* handle the zero case */
	if (n == 0)
	{
		_putchar('0');
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
		_putchar('0' + nCopy % 10);
	}
	printed += digitCount;
	return (printed);
}
