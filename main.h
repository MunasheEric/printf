#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct arrange - print formatting function
 * @symb: the format specifier
 * @function: function to be used for specifier
 */
typedef struct arrange
{
	char symb;
	int (*function)(va_list arg);
} arrange;

int _printf(const char *format, ...);
int print_string(va_list list);

#endif
