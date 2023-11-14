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
	int i, cPrinted = 0;

	format_t arrFormat[] = {
		{'c', char_format},
		{'s', str_format},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				cPrinted++;
				format++;
			}
			i = 0;
			while (arrFormat[i].spc != '\0')
			{
				if (arrFormat[i].spc == *format)
				{
					cPrinted += arrFormat[i].p_format(args);
break;
				}
				i++;
			}
			format++;
		}
		_putchar(*format);
		cPrinted++;
		format++;
	}
	va_end(args);
	return (cPrinted);
}
