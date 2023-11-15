#include "main.h"

/**
  * char_format - prints a .
  * @args: argument at the args variadic list.
  *
  * Return: the number of printed characters.
  */
int char_format(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
  * str_format - prints a string of characters.
  * @args: argument at the args variadic list.
  *
  * Return: the number of printed characters.
  */
int str_format(va_list args)
{
	int cPrinted = 0;
	char *str = va_arg(args, char *);

	if (str == (char *)0)
		str = "(null)";

	cPrinted = _puts(str);

	return (cPrinted);
}

/**
  * int_format - prints a integer.
  * @args: argument at the args variadic list.
  *
  * Return: the number of printed characters.
  */
int int_format(va_list args)
{
	int cPrinted = 0, n = va_arg(args, int);
	char *str = _itoi(n);

	if (str == NULL)
		return (0);
	else
		cPrinted = _puts(str);

	free(str);
	return (cPrinted);

