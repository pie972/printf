#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * get_size - calculates the size of the argument
 * @format: format string
 * @i: arguments
 *
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int n = *i + 1;
	int size = 0;

	if (format[n] == '1')
		size = L_SIZE;
	else if (format[n] == 'h')
		size = S_SIZE;
	if (size == 0)
		*i = n - 1;
	else
		*i = n;
	return (size);
}
