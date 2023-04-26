#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * flag - active flags
 * @format: format
 * @i: parametre value
 * Return: flag
 */
int flag(const char *format, int *i)
{
	int n;
	int m;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (m = *i + 1; format[m] != '\0'; m++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[m] == FLAGS_CH[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}
		if (FLAGS_CH[n] == 0)
			break;
	}

	*i = m - 1;
	return (flags);
}
