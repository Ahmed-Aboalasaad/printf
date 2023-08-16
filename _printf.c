#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints
 *
 * @format: the formatter string
 * Return: the nubmer of characters printed
 */
int _printf(const char* format, ...)
{
    va_list args;
    int skip = 0;
    unsigned long int i, printed = 0;

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
            else if (format[i + 1] == 'd' || format[i + 1] == 'i') /* integer placeholder */
                printed += print_integer(va_arg(args, int));
            else if (format[i + 1] == 'b') /* binary conversion */
                printed += print_binary(va_arg(args, unsigned int));
            else if (format[i + 1] == '%') /* uaual percentage character */
                printed += _putchar('%');
            else
                skip = 0;
        }
        else /* usual character */
            printed += _putchar(format[i]);
    }
    va_end(args);

    return printed;
}
