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
	int len = _printf("%S\n", "Best\nSchool");
	
	printf("%d\n", len);
	return (0);
}
