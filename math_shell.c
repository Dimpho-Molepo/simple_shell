#include "shell.h"

/**
 * _atoi - Convert a string to an integer
 * @str: The string to be converted to an integer
 *
 * Return: The integer value represented by the string,
 * -1 if the string contains non-numeric characters
 */

int _atoi(char *str)
{
	int x, num;

	x = num = 0;
	while (str[x] != '\0')
	{
		if (str[x] < '0' || str[x] > '9')
			return (-1);
		num = num * 10;
		num += str[x] - '0';
		x++;
	}
	return (num);
}
