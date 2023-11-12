#include "main.h"

/**
 * _printf - prints the function
 * @format: this identifies the function to e printed
 * Return: sum of string
 */
int _printf(const char *format, ...)
{
	int m, n, count, find;
	va_list list;

	set arguments[] = {
	{'c', display_char},
	{'i', output_integer},
	{'s', _strlen},
	{'r', output_rot13},
	{'R', output_rev},
	{'d', output_decimal},
	};

	if (format == NULL)
		return (-1);

	va_start(list, format);

	count = 0;

	for (m = 0; *(format + m); m++)
	{
	if (*(format + m) == '%')
	{
	if (*(format + m + 1) == '\0')
	continue;
	find = 0;

	for (n = 0; n < 6; n++)
	{
	if (*(format + m + 1) == arguments[n].spec)
	{
	count += arguments[n].print(list);
	find = 1;
	format++;
	break;
	}
	}

	if (find != 1)
	{
	if (*(format + m + 1) == '%')
	{
	count += write(1, "%", 1); format++;
	
	}
	else
	count += write(1, (format + m), 1);
	}
	}
	else
	{
	count += write(1, (format + 1), 1);
	}
	}
	va_end(list);

	return (count);
}
