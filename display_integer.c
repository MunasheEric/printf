#include "main.h"

/**
 * display_integer - prints character
 * @types: argument list
 * @buffer: array to handle print
 * @flags: total flags available
 * @width: Width
 * @precision: precision
 * @size: size
 * Return: sum of chars printed
 */
int print_character(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));

}
/****** display text  ******/
/**
 * display_text - display a text
 * @types: argument list
 * @buffer: array to handle print
 * @flags: total flags available
 * @width: Width
 * @precision: precision
 * @size: size
 * Return: sum of chars printed
 */
int display_text(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, m;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (m = width - length; m > 0; m--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (m = width - length; m > 0; m--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * output_percent - output the percent sign
 * @types: argument list
 * @buffer: array to handle print
 * @flags: total flags available
 * @width: Width
 * @precision: precision
 * @size: size
 * Return: num ofchars
 */
int output_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	return (write(1, "%%", 1));
}

/**
 * display_integer - display integer
 * @flags: total flags available
 * @width: Width
 * @size: size
 * @precision: precision
 * @buffer: array to handle print
 * Return: num of chara
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int m = BUFSIZ - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[m--] = '0';

	buffer[BUFSIZ - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[m--] = (num % 10) + '0';
		num /= 10;
	}

	m++;
	
	return (write_number(is_negative, m, buffer, flags, width, precision, size));
}

/**
 * output_binary -  output binary
 * @size: size
 * @precision: precision
 * @buffer: array to handle print
 * @flags: total flags available
 * @width: Width
 * @types: argument list
 * Return: num of chars
 */
int output_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int c, b, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	c = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	a[0] = c / b;
	for (j = 1; j < 32; j++)
	{
		b /= 2;
		a[j] = (c/ b % 2);
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];
			
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
