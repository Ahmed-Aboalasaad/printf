#include "main.h"
#include <limits.h>

/**
 * pow_int - power function
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

    while (p > 1)
    {
        b *= tmp;
        p--;
    }
    return (b);
}

/**
 * print_number - Prints a number
 * @n: the number to be printed
 *
 * Retrun: the number of digits printed
 */
int print_integer(int n)
{
    int copy = n, digitCount = 0, digitCountCopy, extraDigit = '#';

    /* if n is the smallest number possible, take a digit in your pocket */
    if (n == INT_MIN)
    {
        extraDigit = -1 * (n % 10);
        n /= 10;
    }
    /* handle the zero case */
    if (n == 0)
    {
        _putchar(48);
        return (1);
    }
    /* handle negative values */
    if (n < 0)
    {
        _putchar(45);
        n = -n;
        copy = n;
    }
    /* count the digits */
    while (copy > 0)
    {
        copy /= 10;
        digitCount++;
    }
    /* print the number */
    digitCountCopy = digitCount;
    for (; digitCountCopy > 0; digitCountCopy--)
    {
        copy = n;
        copy /= int_pow(10, digitCountCopy - 1);
        _putchar(copy % 10 + 48);
    }
    if (extraDigit != '#')
        _putchar(extraDigit + 48);
    return (digitCount);
}
