#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct arguments - interface for printing
 * @id: the character that determines the specifier
 * @fun: function pointer
 */
typedef struct arguments
{
	char id;
	int (*fun)(va_list);
} argument;

int _printf(const char *format, ...);
int _print_char(va_list ls);
int _print_mod(va_list ls);
int _print_string(va_list ls);
int _print_int(va_list ls);

#endif
