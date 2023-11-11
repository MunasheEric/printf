#include <stdio.h>

/**
 * display_integer - this function display the integer
 * @num: the value initialized
 * Return: Always success 0
 */
void display_integer(int num)
{
	printf("%d\n", num);
}

/**
 * main - the main function
 * Return: Always success 0
 */
int main(void)
{
	int value = 42;	
	/* Presenting the integer using a custom function */
	display_integer(value);
	/* Utilizing the same function for another integer */
	display_integer(77);
	return (0);
}
