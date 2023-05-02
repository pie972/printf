#include "main.h"

/**
 * print - print char.
 * @str: string.
 *
 * Return: string length.
 **/
int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);

	return (i);
}
/**
 * itoa - integer to ascii
 * @num: num
 * @base: base
 *
 * Return: char
 **/
char *itoa(long int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 * Return: Integer
 **/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
/**
* _putstr - print a string in stdout
* @str: string
* Return: noting
*/
void _putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
/**
* hex_up - convert decimal to hexadecimal uppercase
* @nb: number
* @size: size for printf
*/

void hex_up(unsigned int nb, int *size)
{

	if (nb / 16)
	{
		hex_up(nb / 16, size);
	}
	*size += 1;
	if (nb % 16 < 10)
		_putchar('0' + nb % 16);
	else
		_putchar('A' + ((nb % 16) - 10));
}
/**
* hex_S - convert decimal to hexadecimal Uppercase
* @nb: number
* @size: size for printf
*/
void hex_S(unsigned int nb, int *size)
{
	int check = 1;

	if (nb / 16)
	{
		hex_up(nb / 16, size);
	}
	if (check == 1)
	{
		_putchar('0');
		*size += 1;
	}
	*size += 1;
	if (nb % 16 < 10)
		_putchar('0' + nb % 16);
	else
		_putchar('A' + ((nb % 16) - 10));
	check = 0;
}
