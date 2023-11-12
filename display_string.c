#include "main.h"

/**
 * display_string - this function prints the string
 * @s: string to be printed
 * Return: nothing to return
 */
int display_string(const char *s, const unsigned int n, ...)
{
	char *str;
	unsigned int k;
	va_list valist;

	va_start(valist, n);

	for (k = 0; k < n; k++)
	{
		str = va_arg(valist, char *);

		if (str)
			printf("%s", str);
		else
			printf("(nil)");
		if (k < n - 1)
			if (s)
				printf("%s", s);
	}

	printf("\n");
	va_end(valist);
}
