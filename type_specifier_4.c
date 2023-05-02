#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
* bin_setter - convert to binary
* @valist: number in decinal
* Return: number of chars printed;
*/
int bin_setter(va_list valist)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(valist, unsigned int), 2);

	size = print(p_buff);

	return (size);
}
