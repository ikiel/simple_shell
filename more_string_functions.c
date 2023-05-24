#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: int less than, equal to, or greater than 0 if s1 is, respectively
 * less than, equal to, or greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;

	do {
		result = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (result == 0);

	return (result);
}

/**
 * _atoi - turn a string into an int
 * @s: string to evaluate
 * Return: n the value of the first number in the string
 */
int _atoi(char *s)
{
	int n, tmp, len, mul = 1;

	n = 0;
	tmp = 0;

	len = _strlen(s);
	len--;
	while (len >= 0)
	{
		tmp = n;
		n = n + (s[len] - '0') * mul;
		if (n < tmp || n > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (n);
}
