#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * unsig_setter - Print a unsigned int
 * @valist: Number to print
 *
 * Return: Length of the number;
 */
int unsig_setter(va_list valist)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(valist, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
 * octal_setter - Print a unsigned octal
 * @valist: Number to print
 *
 * Return: Length of the number;
 */
int octal_setter(va_list valist)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(valist, unsigned int), 8);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}
/**
* print_hex - function that prints an unsigned int in hexadecimal
* @n: unsigned to be printed
* @c: case of printing (0 = lower, 1 = upper)
* Descriptions: prints unsigned in hexadecimal with _putchar
* Return: size the output;
*/
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int len, powten, j, digit, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 16;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
 * hex_low_setter - Print a number in hexadecimal format
 * @valist: Number to print
 *
 * Return: Length of the number;
 */
int hex_low_setter(va_list valist)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(valist, unsigned int), 16);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}
/**
 * hex_upp_setter - Print a number in hexadecimal format
 * @valist: Number to print
 *
 * Return: Length of the number;
 **/
int hex_upp_setter(va_list valist)
{
	return (print_hex(va_arg(valist, unsigned int), 1));
}
