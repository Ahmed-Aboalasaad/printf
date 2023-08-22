#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define BUFFERSIZE 1024

/**
 * struct Mapping - maps every specifier with its corresponding printer
 *
 * @type: the specifier character
 * @printer: function pointer to the printer
 * Description: used to map every specifier character (d for example)
 * with its corresponding printer (print_int() in this case)
 */
typedef struct Mapping
{
	char type;
	int (*printer)(va_list args, char *buffer);
} Mapping;

/* Buffer */
void flush(char *buffer);
int buffer_char(char c, char *buffer);
int buffer_string(char *str, char *buffer);


/* Printers */
int _printf(const char *format, ...);
int print_string(va_list args, char *buffer);
int print_int(va_list args, char *buffer);
int print_binary(va_list args, char *buffer);
int print_unsigned_int(va_list args, char *buffer);
int print_octal(va_list args, char *buffer);
int print_hex(unsigned int n, char capital, char *buffer);
int print_small_hex(va_list args, char *buffer);
int print_capital_hex(va_list args, char *buffer);
int print_unprintable_string(va_list args, char *buffer);
int print_address(va_list args, char *buffer);

/* Testers */
void string_tester(void);
void int_tester(void);

#endif
