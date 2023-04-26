#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * percent_setter - %
 *
 * Return: 1.
 */
int percent_setter(__attribute__((unused))va_list valist)
{
	_putchar('%');
	return (1);
}
/**
 * char_setter - writes the character c to stdout
 * @valist: The character to print
 *
 * Return: 1.
 */
int char_setter(va_list valist)
{
	_putchar(va_arg(valist, int));
	return (1);
}
/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 *
 * Return: 1.
 */
int string_setter(va_list valist)
{
	char *str;
	int  i = 0;

	str = va_arg(valist, char *);
	if (str == NULL)
  {
 		str = "(null)";
  }
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
/**
* dec_setter - function that prints an decimal
* @valist: integer to print
* Descriptions: prints digit with _putchar
* Return: size the output text
*/
int dec_setter(va_list valist)
{
	int len, powten, j, digit, n, count = 0;
  unsigned int num;

	n = va_arg(valist, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
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
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
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
* int_setter - function that prints an integer
* @valist: integer to print
* Descriptions: prints digit with _putchar
* Return: size the output text
*/
int int_setter(va_list valist)
{
	int len, powten, j, digit, n, count = 0, num;

	n = va_arg(valist, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
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
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
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

