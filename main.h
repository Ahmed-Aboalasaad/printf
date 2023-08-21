#ifndef MAIN_H
#define MAIN_H

#define BUFFERSIZE 1024
#define next_argument(args, type) va_arg(args, )

typedef struct Mapping
{
    char type;
    int (*printer)(void *ptr, char *buffer);
}Mapping;


int _printf(const char *format, ...);
int print_string(char *s, char *buffer);
int print_int(int n, char *buffer);
int print_binary(unsigned int n, char *buffer);
int print_unsigned_int(unsigned int n, char *buffer);
int print_octal(unsigned int n, char *buffer);
int print_small_hex(unsigned int n, char *buffer);
int print_capital_hex(unsigned int n, char *buffer);
int add_to_buffer(char c, char *buffer);
int print_unprintable_string(char *s, char *buffer);
int print_address(unsigned long int p, char *buffer);

#endif
