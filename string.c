#include "main.h"

/**
 * print_string - prints a string without printf
 *
 * @s: the string
 * Return: the number of characters printed
 */
int print_string(char* s)
{
    int i;

    for (i = 0; s[i]; i++)
        _putchar(s[i]);
    return (i);
}
