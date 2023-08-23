#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = printf("%c\n", 'H');
	len2 = _printf("%c\n", 'H');
	printf("%d, %d\n", len1, len2);

	return (0);
}
