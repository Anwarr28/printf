#include "main.h"

/**
  * _printf - function produces output according to a format.
  * @format: the format string to be printed.
  *
  * Return: the number of character printed.
  */
int _printf(const char *format, ...)
{
	va_list args;
	int cPrinted = 0;

	format_t arrFormat[] = {
		{'c', char_format},
		{'s', str_format},
		{'\0', NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			cPrinted++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (0);
			cPrinted += select_format(&format, args, arrFormat);
		}
		format++;
	}
	va_end(args);
	return (cPrinted);
}

/**
  * select_format - select the the format.
  * @str: a pointer to the formated string.
  * @args: the list of argument.
  * @arr: an array of struct.
  *
  * Return: the number of printed characters.
  */
int select_format(const char **str, va_list args, format_t *arr)
{
	int i = 0, cPrinted = 0;

	if (**str == '%')
	{
		_putchar('%');
		cPrinted++;
		str++;
	}
	else
	{
		while (arr[i].spc != '\0')
		{
			if (arr[i].spc == **str)
			{
				cPrinted += arr[i].p_format(args);
				break;
			}
			i++;
		}
		if (arr[i].spc == '\0')
		{
			_putchar('%');
			_putchar(**str);
			cPrinted += 2;
		}
	}
	return (cPrinted);
}
