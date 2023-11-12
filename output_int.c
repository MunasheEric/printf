#include "main.h"

/**
 * output_int - output the integer followed by new line
 * @separator: string to be printed
 * @n: this is the nber of integers
 * Return: return nothing
 */
void output_int(const char *separator, const unsigned int n, ...)
{
	unsigned int c;
	va_list list;
	char *sep;

	if (separator == NULL || *separator == 0)
		sep = "";
	else
		sep = (char *) separator;
	va_start(list, n);

	if (n > 0)
		printf("%d", va_arg(list, int));
	for (c = 0; c < n; c++)
		printf("%s%d", sep, va_arg(list, int));
	printf("\n");
	va_end(list);
}
