#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
  * _puts - prints a string of characters.
  * @str: the string to be printed.
  *
  * Return: the number of characters printed.
  */
int _puts(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		return (0);
	}
	len = _strlen(str);

	return (write(STDOUT_FILENO, str, len));
}
