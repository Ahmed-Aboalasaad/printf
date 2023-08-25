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
	len1 = printf("Ahmed% ");
	printf("\n");
	len2 = _printf("Ahmed% ");
	printf("\n");
	printf("%d, %d\n", len1, len2);

	return (0);
}
