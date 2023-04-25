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
int string_setter(va_list valist);
int char_setter(va_list valist);
int int_setter(va_list valist);
int dec_setter(va_list valist);

/* utils.c */
int _strlen(const char *);

/**
  * struct code_format - Struct format
  *
  * @opt: The specifiers
  * @f: The function associated
  */
typedef struct format
{
	char *opt;
	int (*f)(va_list);
} format_t;

#endif /* MAIN */
