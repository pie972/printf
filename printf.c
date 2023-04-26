#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
  * find_function - function that finds formats for _printf
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_format find_f[] = {
		{"%", percent_setter},
		{"c", char_setter},
		{"s", string_setter},
		{"d", dec_setter},
		{"i", int_setter},
		{"b", bin_setter},
		{"u", unsig_setter},
		{"o", octal_setter},
		{"x", hex_low_setter},
		{"X", hex_upp_setter},
		{'p', pointer_setter},
		{'r', rev_string_setter},
		{'R', rot_setter}
		{NULL, NULL}
	};

	while (find_f[i].opt)
	{
		if (find_f[i].opt[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
  * _printf - function that produces output according to a format.
  * @format: format (char, string, int, decimal)
  * Return: size the output text;
  */
int _printf(const char *format, ...)
{
	va_list valist;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (cprint);
}
