#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _strlen(char *s);
int output_decimal(va_list args);
int _putchar(char c);
void print_integer(const char *separator, const unsigned int n, ...);
int  print_string(const char *s, const unsigned int n, ...);
char *print_rot13(char *s);
void rev_string(char *s);

#endif
