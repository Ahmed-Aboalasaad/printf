#include "main.h"

/**
 * get_specifier - finds the specifier after some index in
 * the format string
 *
 * @format: the format string
 * @startIndex: the index from which we should start searching
 * Return: the spcifier character, or NULL when no specifiers are found
 */
char get_specifier(const char *format, int startIndex)
{
	int i, j;
	char specifiers[] = "csdib%uxXSp";

	for (i = startIndex; format[i]; i++)
		for (j = 0; specifiers[j]; j++)
			if (format[i] == specifiers[j])
				return (specifiers[j]);
	return ('\0');
}


/**
 * get_printer - gets the right printer function
 *
 * @format: the format string given to _printf()
 * @currentIndex: the index at which the '%' was found
 * Return: a function pointer to the printer,
 * NULL when specifiers were found
 */
int (*get_printer(const char *format, int currentIndex))(va_list, char *)
{
	int i;
	Mapping mappings[10] = {
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_unsigned_int},
		{'x', print_small_hex},
		{'X', print_capital_hex},
		{'S', print_unprintable_string},
		{'p', print_address},
		{'\0', NULL}
	};
	char c = get_specifier(format, currentIndex + 1);

	/* no specifier was found*/
	if (c == '\0')
		return (NULL);

	/* get the corresponding printer */
	for (i = 0; mappings[i].printer; i++)
		if (c == mappings[i].type)
			return (mappings[i].printer);

	/* reaching here means a problem happened (recheck your mappings) */
	return (NULL);
}

/**
 * _printf - prints a formatted string
 *
 * @format: the formatter string
 * Return: the nubmer of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned long int i, skip = 0, printed = 0;
	char *buffer;
	int (*printer)(va_list, char *);

	/* Input Validation */
	if (format == NULL)
		return (-1);
	/* Make the local buffer */
	buffer = malloc(sizeof(*buffer) * BUFFERSIZE + 1);
	if (buffer == NULL)
		return (-1);
	buffer[0] = '\0';

	/* Parse the format */
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
			printer = get_printer(format, i);
			if (!printer)
				return (0);

			printed += printer(args, buffer);
		}
		else /* non-percentage character */
			printed += buffer_char(format[i], buffer);
	}
	va_end(args);
	flush(buffer);
	free(buffer);
	return (printed);
}
