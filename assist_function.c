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

/**
  * _itoa - turns an integer into a stirg.
  * @n: the number to be converted.
  *
  * Return: a pointerr to the string number.
  */
char *_itoa(int n)
{
	int temp = n, dvd = 1, nChar = 1, i = 0;
	char *p = NULL;

	if (n < 0)
	{
		n *= -1;
		temp = n;
		i++;
		nChar++;
	}
	while (temp > 9)
	{
		temp /= 10;
		dvd *= 10;
		nChar++;
	}
	p = malloc((nChar + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (i == 1)
		*p = '-';
	while (i < nChar)
	{
		*(p + i) = n / dvd + '0';
		n %= dvd;
		dvd /= 10;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
