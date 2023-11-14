#include "main.h"

/**
  * _strlen - calculate the length of a string.
  * @str: the string to get its length.
  *
  * Return: the length of the string. 0 if the string == NULL.
  */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len])
		len++;

	return (len);
}
