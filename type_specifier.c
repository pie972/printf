#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * percent_setter - %
 * @valist: The percent to print
 * 
 * Return: 1;
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
 * Return: 1;
 */
int char_setter(va_list valist)
{
	_putchar(va_arg(valist, int));
	return (1);
}
/**
 * string_setter - writes the string s to stdout
 * @valist: The string to print
 * Descriptions: prints string
 * Return: 1;
 */
int string_setter(va_list valist)
{
	char *str;
	int  i = 0;
	str = va_arg(valist, char *);
	
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
/**
* dec_setter - function that prints an decimal
* @valist: The integer to print
* Descriptions: prints digit with _putchar
* Return: size the output text;
*/
int dec_setter(va_list valist)
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
/**
* int_setter - function that prints an integer
* @valist: integer to print
* Descriptions: prints digit with _putchar
* Return: size the output text;
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
/**
 * pointer_setter - Print a number in hexadecimal format
 * @valist: Number to print
 *
 * Return: Length of the number;
 **/
int pointer_setter(va_list valist)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(valist, unsigned long int), 16);

	if (!_strcmp(p_buff, "0"))
		return (print("(nil)"));

	size = print("0x");

	if (!_strcmp(p_buff, "-1"))
		size += print("ffffffffffffffff");
	else
		size += print(p_buff);

	return (size);
}
/**
* rev_string_setter - prints astring in reverse
* @valist: string to print
* Return: number of chars printed;
*/
int rev_string_setter(va_list valist)
{
	char *st;
	int i, j = 0;

	st = va_arg(valist, char *);
	if (st == NULL)
		st = ")llun(";
	for (i = 0; st[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}
/**
 * rot13 - Encodes a string using rot13.
 * @s: String to enconde
 * Return: String encode
 */
int rot13(char *s)
{
	int i, j;
	char *input, *rot13;

	input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if (s[i] == input[j])
			{
				_putchar(output[j]);
				break;
			}
		}

		if (!input[j])
			_putchar(s[i]);
	}
	return (i);
}
/**
  * rot_setter - encodes a string into rot13.
  * @valist: string to convert
  * Return: size the output text;
  */
int rot_setter(va_list valist)
{
	char *p;
	int p_len;

	p = va_arg(list, char *);
	p_len = rot13((p != NULL) ? p : "(ahyy)");

	return (p_len);
}
