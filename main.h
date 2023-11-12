#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format - converter for printf
 * @ph: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */
typedef struct format
{
		char *ph;
			int (*function)();
} convert;

int _printf(const char *format, ...);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
#endif
