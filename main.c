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
	int len1 = printf("%s\n", "Ahmed Aboalesaad");
	int len2 = _printf("%s\n", "Ahmed Aboalesaad");
	printf("%d, %d\n", len1, len2);


	return (0);
}
