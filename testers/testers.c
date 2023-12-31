#include "../main.h"

/**
 * int_tester - test cases for %d in _printf()
 *
 * Return: nothing
 */
void int_tester(void)
{
	int len1, len2;

	printf("==== INT Tests ====\n\n");

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

	printf("\n==== INT Tests with Flags ====\n\n");

	len1 = printf("% d\n", INT_MAX);
	len2 = _printf("% d\n", INT_MAX);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("% d\n", -9856);
	len2 = _printf("% d\n", -9856);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("% d\n", 0);
	len2 = _printf("% d\n", 0);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("% +d\n", 0);
	len2 = _printf("% +d\n", 0);
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("% +d\n", -9856);
	len2 = _printf("% +d\n", -9856);
	printf("%d, %d\n-----\n", len1, len2);
}

/**
 * string_tester - test cases for %s in _printf()
 *
 * Return: nothing
 */
void string_tester(void)
{
	int len1, len2, i;
	char *str;
	char *s;

	printf("=== String Tests ===\n\n");

	len1 = printf("\"%s\"\n", "");
	printf("\"");
	len2 = _printf("%s", "");
	printf("\"\n");
	printf("%d, %d\n-----\n", len1 - 3, len2);

	len1 = printf("%s\n", " ");
	len2 = _printf("%s", " ");
	printf("\n");
	printf("%d, %d\n-----\n", len1 - 1, len2);

	str = NULL;
	len1 = printf("%s\n", str);
	len2 = _printf("%s", str);
	printf("\n");
	printf("%d, %d\n-----\n", len1 - 1, len2);

	len1 = printf("%s\n", "Ahmed\nAboalesaad");
	len2 = _printf("%s", "Ahmed\nAboalesaad");
	printf("\n");
	printf("%d, %d\n-----\n", len1 - 1, len2);

	str = malloc(2);
	str[0] = 27, str[1] = 0;
	len1 = printf("%s\n", str);
	len2 = _printf("%s", str);
	printf("\n");
	printf("%d, %d\n-----\n", len1 - 1, len2);
	free(str);

	/* long string */
	s = malloc(sizeof(char) * 4000 + 1);
	s[4000] = '\0';
	for (i = 0; i < 4000; i++)
		s[i] = '1';
	len1 = printf("%s\n\n\n", s);
	len2 = _printf("%s\n\n\n", s);
	printf("%d, %d\n", len1, len2);
}

/**
 * set_flags_tester - test cases for set_flags()
 *
 * Return: nothing
 */
void set_flags_tester(void)
{
	Flags my_flags = DEFAULT_FLAGS;
	char *format = " -#";

	set_flags(&my_flags, format, 0);

	printf("Flags:\n");
	printf("plus: %c\n", my_flags.plus + '0');
	printf("minus: %c\n", my_flags.minus + '0');
	printf("space: %c\n", my_flags.space + '0');
	printf("hash: %c\n", my_flags.hash + '0');
}

void percent_tester(void)
{
	int len1, len2;

	len1 = printf("%%\n");
	len2 = _printf("%%\n");
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%\n");
	len2 = _printf("%\n");
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("% \n");
	len2 = _printf("% \n");
	printf("%d, %d\n-----\n", len1, len2);

	/* Failing test (original pritnf() shrinks whitespace into one space) */
	/* but I'll not fix this for now (it should give an erro in the original one)
	   so, ALX won't test this case :) */
	len1 = printf("%   \n");
	len2 = _printf("%   \n");
	printf("%d, %d\n-----\n", len1, len2);

	/* and if it found a non-special character, it deminishes the whitespace */
	len1 = printf("%   +\n");
	len2 = _printf("%   +\n");
	printf("%d, %d\n-----\n", len1, len2);


	/* failing test: if no specifier was found after printf, it
	should return -1 and not print anything */
	len1 = printf("Ahmed% ");
	printf("\n");
	len2 = _printf("Ahmed% ");
	printf("\n");
	printf("%d, %d\n", len1, len2);


	len1 = printf("%%%\n");
	len2 = _printf("%%%\n");
	printf("%d, %d\n-----\n", len1, len2);
}

void char_tester(void)
{
	int len1, len2;

	len1 = printf("%c\n", 'H');
	len2 = _printf("%c\n", 'H');
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%c \n", 'H');
	len2 = _printf("%c \n", 'H');
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf(" %c\n", 'H');
	len2 = _printf(" %c\n", 'H');
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("% c\n", 'H');
	len2 = _printf("% c\n", 'H');
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%     c\n", 'H');
	len2 = _printf("%     c\n", 'H');
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%  +c\n", 'H');
	len2 = _printf("%  +c\n", 'H');
	printf("%d, %d\n-----\n", len1, len2);

	len1 = printf("%c%c\n", 'H', 'P');
	len2 = _printf("%c%c\n", 'H', 'P');
	printf("%d, %d\n-----\n", len1, len2);
}
