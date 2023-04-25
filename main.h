#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* _putchar.c */
int _putchar(char c);

/* printf.c */
int _printf(const char *format, ...);

/* printers */
int percent_setter(__attribute__((unused))va_list valist);
int char_setter(va_list valist);
int string_setter(va_list valist);
int dec_setter(va_list valist);
int int_setter(va_list valist);


/**
  * struct format - Typedef struct
  *
  * @opt: The specifiers
  * @f: The function associated
  */
typedef struct format
{
	char *opt;
	int (*f)(va_list);
} code_format;

#endif /* MAIN */
