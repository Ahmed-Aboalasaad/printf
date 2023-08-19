#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - prints a formatted string
 *
 * @format: the formatter string
 * Return: the nubmer of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int skip = 0;
	unsigned long int i, printed = 0;

	/* Input Validation */
	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (skip)
		{
			skip = 0;
			continue;
		}

		if (format[i] == '%')
		{
			skip = 1;
			if (format[i + 1] == 'c') /* character placeholder */
				printed += _putchar(va_arg(args, int));
			else if (format[i + 1] == 's') /* string placeholder */
				printed += print_string(va_arg(args, char*));
			/* integer placeholder */
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				printed += print_int(va_arg(args, int));
			else if (format[i + 1] == 'b') /* binary conversion */
				printed += print_binary(va_arg(args, unsigned int));
			else if (format[i + 1] == '%') /* a percentage character */
				printed += _putchar('%');
			else if (format[i + 1] == 'u')
				printed += print_unsigned_int(va_arg(args, unsigned int));
			else if (format[i + 1] == 'o')
				printed += print_octal(va_arg(args, unsigned int));
			else if (format[i + 1] == 'x' || format[i + 1] == 'X')
				printed += print_hex(va_arg(args, unsigned int), format[i + 1] == 'X');
			else
				skip = 0;
		}
		else /* non-percentage character */
			printed += _putchar(format[i]);
	}
	va_end(args);

	return (printed);
}
