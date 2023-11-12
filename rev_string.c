#include "main.h"

/**
 * rev_string - this function reverse the string
 * @s: string to be reversed
 */
void rev_string(char *s)
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
