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
	int nChar = 1, i = 0;

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
	return (convert_str(n, dvd, nChar, i));
}

/**
  * convert_str - convert a string to integer.
  * @n: the number to be converted.
  * @dvd: the number to divide n with.
  * @nChar: number of characters needed to allocate memo.
  * @i: flag to print the -.
  *
  * Return: a pointer to the converted number.
  */
char *convert_str(long int n, long int dvd, int nChar, int i)
{
	char *p = malloc((nChar + 1) * sizeof(char));

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

/**
  * base_convertor - turns a decimal number to the specified base.
  * @n: the number to be converted.
  * @base: the base of the converted number.
  *
  * Rrturn: a pointer to a string of the converted number.
  */
char *base_convertor(long int n, int base)
{
	char *str = NULL;
	int len, i = 0;

	if (base == 2)
	{
		len = _log(n, base) + 2;
		str = malloc(sizeof(char) * len);
		if (str == NULL)
			return (NULL);

		while (i < len - 1)
		{
			*(str + i) = n % base + '0';
			n /= base;
			i++;
		}
		*(str + i) = '\0';
		reverse_str(str);
	}
	return (str);
}

/**
  * reverse_str - rotates a string.
  * @str: a pointer to the string to be rotated.
  *
  * Return: a pointer to the rotated string.
  */
char *reverse_str(char *str)
{
	char temp;
	int i, len = _strlen(str);

	for (i = 0; i < (len - 1) / 2; i++, len--)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
	}
	return (str);
}

/**
 * _log - calculates the base-2 logarithm of a number
 * @n: the number to calculate the logarithm of
 * @base: the base will be used.
 *
 * Return: the base logarithm of n
 */
int _log(long int n, int base)
{
	int log = 0;

	while (n > 1)
	{
		n /= base;
		log++;
	}
	return (log);
}
