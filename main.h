#ifndef MAIN_H
#define MAIN_H

/* libraries */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
  * struct format - for handling format specifiers.
  * @spc: a char to match with the format specifier.
  * @p_format: a pointer to the function to handle the format.
  */
typedef struct format
{
	char spc;
	int (*p_format)(va_list);
} format_t;

/* the main function */
int _printf(const char *format, ...);
int select_format(const char **str, va_list args, format_t *arr);

/** print format functions */
int char_format(va_list args);
int str_format(va_list args);
int int_format(va_list args);

/* print to standard output functions */
int _putchar(char c);
int _puts(char *str);

/* assist functions */
int _strlen(char *str);
char *_itoa(long int n);
char *convert_str(long int n, long int dvd, int nChar, int isMin, int i);

#endif /* MAIN_H */
