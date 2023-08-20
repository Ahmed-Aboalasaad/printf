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
	int x;
	int len1 = printf("%p\n", NULL);
	int len2 = _printf("%p\n", NULL);
	printf("%d, %d\n", len1, len2);
	return (0);
}
