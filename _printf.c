#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * flush - print the buffer contents to the standard output
 *
 * @buffer: the buffer to flush
 * Return: nothing
 */
void flush(char *buffer)
{
	int i, size = 0;

	for (i = 0; buffer[i]; i++)
		size++;
	write(STDOUT_FILENO, buffer, size);
	buffer[0] = '\0';
}

/**
 * add_to_buffer - adds a character to the buffer
 *
 * @c: the character to be added
 * @buffer: pointer to the buffer
 * Return: nothing
 */
int add_to_buffer(char c, char *buffer)
{
	int i, size = 0;

	for (i = 0; buffer[i]; i++)
		size++;
	if (size < 1024)
	{
		buffer[size] = c;
		buffer[size + 1] = '\0';
		size++;
	}
	else if (size == 1024)
		flush(buffer);
	return (1);
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
	int skip = 0;
	unsigned long int i, printed = 0;
	char *buffer;

	/* Input Validation */
	if (format == NULL)
		return (-1);

	buffer = malloc(sizeof(*buffer) * BUFFERSIZE + 1);
	if (buffer == NULL)
		return(-1);
	buffer[BUFFERSIZE] = '\0';

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
				printed += add_to_buffer(va_arg(args, int), buffer);
			else if (format[i + 1] == 's') /* string placeholder */
				printed += print_string(va_arg(args, char*), buffer);
			/* integer placeholder */
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				printed += print_int(va_arg(args, int), buffer);
			else if (format[i + 1] == 'b') /* binary conversion */
				printed += print_binary(va_arg(args, unsigned int), buffer);
			else if (format[i + 1] == '%') /* a percentage character */
				printed += add_to_buffer('%', buffer);
			else if (format[i + 1] == 'u')
				printed += print_unsigned_int(va_arg(args, unsigned int), buffer);
			else if (format[i + 1] == 'o')
				printed += print_octal(va_arg(args, unsigned int), buffer);
			else if (format[i + 1] == 'x' || format[i + 1] == 'X')
				printed += print_hex(va_arg(args, unsigned int), format[i + 1] == 'X', buffer);
			else
				skip = 0;
		}
		else /* non-percentage character */
			printed += add_to_buffer(format[i], buffer);
	}
	va_end(args);

	flush(buffer);
	free(buffer);
	return (printed);
}
