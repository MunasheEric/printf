#include "main.h"

/**
 * display_char - display a character
 * @val: this is where well get the arguments
 * Return: returns integer
 */
int display_char(va_list val)
{
	char m;

	m = va_arg(val, int);
	_putchar(m);
	return (1);
}
