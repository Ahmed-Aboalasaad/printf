#include "main.h"

/**
 * int_tester - test cases for %d in _printf()
 *
 * Return: nothing
 */
void int_tester(void)
{
	int len1, len2;

	printf("=== INT Tests ===\n\n");

	len1 = printf("%d\n", 150);
	len2 = _printf("%d\n", 150);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%d\n", 0);
	len2 = _printf("%d\n", 0);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%d\n", INT_MIN);
	len2 = _printf("%d\n", INT_MIN);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%d\n", INT_MAX);
	len2 = _printf("%d\n", INT_MAX);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%d\n", -9856);
	len2 = _printf("%d\n", -9856);
	printf("%d, %d\n-----\n", len1, len2);
}

/**
 * string_tester - test cases for %s in _printf()
 *
 * Return: nothing
 */
void string_tester(void)
{
	int len1, len2;
	char *str;

	printf("=== String Tests ===\n\n");

	len1 = printf("\"%s\"\n", "");
	printf("\"");
	len2 = _printf("%s", "");
	printf("\"\n");
	printf("%d, %d\n\n-----\n", len1 - 3, len2);

	len1 = printf("%s\n", " ");
	len2 = _printf("%s", " ");
	printf("\n");
	printf("%d, %d\n\n-----\n", len1 - 1, len2);

	str = NULL;
	len1 = printf("%s\n", str);
	len2 = _printf("%s", str);
	printf("\n");
	printf("%d, %d\n\n-----\n", len1 - 1, len2);
}

/**
 * set_flags_tester - test cases for set_flags()
 *
 * Return: nothing
 */
void set_flags_tester(void)
{
	int i;
	Flags my_flags = DEFAULT_FLAGS;
	char *format = "+#";
	set_flags(&my_flags, format, 0);

	printf("Flags:\n");
	printf("plus: %c\n", my_flags.plus + '0');
	printf("minus: %c\n", my_flags.minus + '0');
	printf("space: %c\n", my_flags.space + '0');
	printf("hash: %c\n", my_flags.hash + '0');
}
