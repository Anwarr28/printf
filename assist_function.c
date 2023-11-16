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
char *_itoa(long int n)
{
	long int temp = n, dvd = 1;
	int isMin = 0, nChar = 1, i = 0;

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			n++;
			isMin = 1;
		}
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
	return (convert_str(n, dvd, nChar, isMin, i));
}

/**
  * convert_str - convert a string to integer.
  * @n: the number to be converted.
  * @dvd: the number to divide n with.
  * @nChar: number of characters needed to allocate memo.
  * @isMin: check if the number is INT_MIN.
  * @i: flag to print the -.
  * Return: a pointer to the converted number.
  */
char *convert_str(long int n, long int dvd, int nChar, int isMin, int i)
{
	char *p = malloc((nChar + 1) * sizeof(char));

	if (p == NULL)
		return (NULL);
	if (i == 1)
		*p = '-';
	while (i < nChar)
	{
		if (isMin == 1 && i == nChar - 1)
		{
			*(p + i) = n / dvd + '0';
			i++;
		}
		*(p + i) = n / dvd + '0';
		n %= dvd;
		dvd /= 10;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
