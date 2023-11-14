#include "main.h"

/**
 * print_rev - function that reverses a string
 * @s: reversing string
 */
void print_rev(char *s)
{
	char tmp;
	int b, len, len1;

	len = 0;
	len1 = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	len1 = len - 1;

	for (b = 0; b < len / 2; b++)
	{
		tmp = s[b];
		s[b] = s[len1];
		s[len1--] = tmp;
	}
}
