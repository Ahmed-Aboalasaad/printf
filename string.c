#include "main.h"

/**
 * print_string - prints a string without printf
 *
 * @args: the argument list of printf
 * @buffer: the buffer
 * Return: the number of characters printed
 */
int print_string(va_list args, char *buffer)
{
	unsigned long int i;
	char *str = va_arg(args, char *);

	if (!str)
	{
		buffer_string("(null)", buffer);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buffer_char(str[i], buffer);
	return (i);
}

/**
 * print_unprintable_string - prints a string with the unprintable
 * characters replaced with their hex represenation
 *
 * @args: the argument list of printf
 * @buffer: the buffer
 * Return: numver of characters printed
 */
int print_unprintable_string(va_list args, char *buffer)
{
	char *s = va_arg(args, char *);
	unsigned long int i, printed = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 0)
			return (0);
		if (s[i] > 31 && s[i] < 127) /* a printable character */
			buffer_char(s[i], buffer);
		else /* unprintable */
		{
			buffer_char('\\', buffer);
			buffer_char('x', buffer);
			if (s[i] < 16)
				buffer_char('0', buffer);
			print_hex(s[i], 1, buffer);
			printed += 3;
		}
		printed++;
	}
	return (printed);
}
