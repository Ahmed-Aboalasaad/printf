#include "main.h"

/**
 * print_string - prints a string without printf
 *
 * @s: the string
 * Return: the number of characters printed
 */
int print_string(char *s, char *buffer)
{
	unsigned long int i;

	for (i = 0; s[i]; i++)
		add_to_buffer(s[i], buffer);
	return (i);
}
