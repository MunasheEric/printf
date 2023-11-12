#include "main.h"

/**
 * output_decimal - this function prints the decimal
 * @args - arguments printed
 * Return: this returns the int
 */
int output_decimal(va_list args)
{
	int m = va_arg(args, int);
	int myNumber, last = n % 10, digit;
	int m = 1;
	int exp = 1;

	n = n / 10;
	myNumber =  0;

	if (last < 0)
	{
		_putchar('-');
		myNumber = -myNumber;
		n = -n;
		last = -last;
		m++;
	}
	if (myNumber > 0)
	{
		while (myNumber / 10 != 0)
		{
			exp = exp * 10;
			myNumber = myNumber / 10;
		}
		myNumber = n;
		while (exp > 0)
		{
			digit = myNumber / exp;

			_putchar(digit + '0');
			myNumber = myNumber - (digit * exp);
			exp = exp / 10;
			m++;
		}
	}
	_putchar(last + '0');

	return (m);
