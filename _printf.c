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
				break;

			if (*format == '%')
			{
				_putchar('%');
				cPrinted++;
			}
			else
			{
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
			}
			if (arrFormat[i].spc == '\0')
			{
				return (-1);
			}
		}
		format++;
	}
	va_end(args);
	return (cPrinted);
}
