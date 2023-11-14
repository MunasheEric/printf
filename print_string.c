#include "main.h"

/**
 * print_string - this fumction peints a string
 * @list: declares a variable
 * Return: string length
 */
int print_string(va_list list)
{
	int len;
	char *s;

	s = va_arg(list, char*);

	if (*s == '\0')
		return (0);

	len = 0;

	while (*s)
	{
		len += write(1, s, 1);
		len++;
	}

	return (len);
}
