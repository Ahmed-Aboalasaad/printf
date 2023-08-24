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
	int i, len1, len2;
	char *s;

	s = malloc(sizeof(char) * 4000 + 1);
	s[4000] = '\0';
	for (i = 0; i < 4000; i++)
		s[i] = '1';
	len1 = printf("%s\n\n\n", s);
	len2 = _printf("%s\n\n\n", s);
	printf("%d, %d\n", len1, len2);

	return (0);
}
