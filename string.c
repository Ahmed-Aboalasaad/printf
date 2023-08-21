#include "main.h"

/**
 * print_string - prints a string without printf
 *
 * @s: the string
 * @buffer: the buffer
 * Return: the number of characters printed
 */
int print_string(char *s, char *buffer)
{
	unsigned long int i;

	for (i = 0; s[i]; i++)
		add_to_buffer(s[i], buffer);
	return (i);
}

/**
 * print_unprintable - prints a string with the unprintable
 * characters replaced with their hex represenation
 *
 * @s: the string to be printed
 * @buffer: the buffer
 * Return: numver of characters printed
 */
int print_unprintable_string(char *s, char *buffer)
{
	unsigned long int i, printed = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 0)
			return (0);
		if (s[i] > 31 && s[i] < 127) /* a printable character */
			add_to_buffer(s[i], buffer);
		else /* unprintable */
		{
			add_to_buffer('\\', buffer);
			add_to_buffer('x', buffer);
			if (s[i] < 16)
				add_to_buffer('0', buffer);
			print_capital_hex(s[i], buffer);
			printed += 3;
		}
		printed++;
	}
	return (printed);
}
