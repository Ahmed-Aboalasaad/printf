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

	len1 = printf("% d\n", 15);
	len2 = _printf("% d\n", 15);
	printf("%d, %d\n", len1, len2);

	return (0);
}
