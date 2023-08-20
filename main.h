#ifndef MAIN_H
#define MAIN_H

#define BUFFERSIZE 1024

int _putchar(char c);
int _printf(const char *format, ...);
int print_string(char *s, char *buffer);
int int_pow(int b, int p);
int print_int(int n, char *buffer);
int print_binary(unsigned int n, char *buffer);
int print_unsigned_int(unsigned int n, char *buffer);
int print_octal(unsigned int n, char *buffer);
int print_hex(unsigned int n, char capital, char *buffer);
int add_to_buffer(char c, char *buffer);
void flush(char *buffer);

#endif
