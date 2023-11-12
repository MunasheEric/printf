#include "main.h"

/**
 * output_rot13 - this function encodes a string using rot13
 * @s: this is pointing to string
 * Return: string containing rot13 letters
 */
char *output_rot13(char *s)
{
	int m, n;

	char i[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (m = 0; s[m]; != '\0'; m++)
	{
		for (n = 0; i[n]; != '\0'; n++)
		{
			if (s[m] == i[n])
			{
				s[m] = rot[n];
				break;
			}
		}
	}
	return (s);
}
