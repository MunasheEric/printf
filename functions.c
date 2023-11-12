#include <stdio.h>
#include <stdlib.h>

/* A function that converts an unsigned int to a binary string */
char *to_binary(unsigned int n)
{
  /* Allocate memory for the binary string */
  char *bin = (char *)malloc(33 * sizeof(char));
  /* Initialize the index of the string */
  int i = 0;
  /* Loop until n becomes zero */
  while (n > 0)
    {
      /* Store the remainder of n divided by 2 as the last digit of the string */
      bin[i] = (n % 2) + '0';
      /* Divide n by 2 to get the next digit */
      n = n / 2;
      /* Increment the index */
      i++;
    }
  /* Add a null terminator to the string */
  bin[i] = '\0';
  /* Reverse the string */
  for (int j = 0; j < i / 2; j++)
    {
      /* Swap the j-th and the (i-j-1)-th characters */
      char temp = bin[j];
      bin[j] = bin[i - j - 1];
      bin[i - j - 1] = temp;
    }
  /* Return the binary string */
  return bin;
}

/* A custom printf function that handles the 'b' specifier */
void my_printf(const char *format, ...)
{
  /* Declare a variable argument list */
  va_list args;
  /* Initialize the list with the format parameter */
  va_start(args, format);
  /* Loop through the format string */
  for (int i = 0; format[i] != '\0'; i++)
    {
      /* If the current character is not '%', print it as it is */
      if (format[i] != '%')
	{
	  putchar(format[i]);
	}
      /* Otherwise, check the next character for the specifier */
      else
	{
	  i++; /* Increment the index */
	  switch (format[i])
	    {
	    /* If the specifier is 'b', print the binary representation of the unsigned int argument */
	    case 'b':
	      /* Get the unsigned int argument from the list */
	      unsigned int n = va_arg(args, unsigned int);
	      /* Convert it to a binary string */
	      char *bin = to_binary(n);
	      /* Print the binary string */
	      printf("%s", bin);
	      /* Free the memory allocated for the binary string */
	 free(bin);
	break;
	/* If the specifier is 'd', print the int argument as a decimal number */
	case 'd':
	/* Get the int argument from the list */
	int d = va_arg(args, int);
	/* Print the decimal number */
	printf("%d", d);
	break;
	    /* If the specifier is 's', print the char* argument as a string */
	case 's':
	      /* Get the char* argument from the list */
	char *s = va_arg(args, char *);
	      /* Print the string */
	printf("%s", s);
	break;
	    /* If the specifier is '%', print a literal '%' */
	case '%':
	putchar('%');
	break;
	    /* If the specifier is invalid, print an error message */
	default:
	printf("Invalid specifier: %%%c\n", format[i]);
	      break;
}
}
	}
  /* End the variable argument list */
va_end(args);
}

/* A main function to test the custom printf function */
int main(void)
{
  /* Declare some variables to print */
unsigned int a = 42;
int b = -10;
char *c = "Hello, world!";
  /* Print them using the custom printf function */
	my_printf("a = %b\n", a);
	my_printf("b = %d\n", b);
 	my_printf("c = %s\n", c);
	my_printf("%%\n");
  /* Return 0 to indicate success */
return (0);
}
