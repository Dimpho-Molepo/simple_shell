#include "shell.h"

/**
 * _erratoi - Transforms a string into an integer.
 *
 * @s: The string to be converted into an integer.
 *
 * Return: Returns 0 if there are no numeric characters in the string, and the converted
 * number otherwise. It returns -1 in case of an error.
 */

int _erratoi(char *s)
{
	int a = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (a = 0;  s[a] != '\0'; a++)
	{
		if (s[a] >= '0' && s[a] <= '9')
		{
			result *= 10;
			result += (s[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Displays an error message.
 *
 * @info: A structure containing parameter and return information.
 * @estr: A string indicating the specific error type.
 *
 * Return: Returns 0 if there are no numeric characters in the string, and the
 * converted number otherwise. It returns -1 in case of an error.
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - A function that displays a decimal (integer) number in base 10.
 *
 * @input: The input number to be printed.
 * @fd: The file descriptor where the output is written.
 *
 * Return: Returns the count of characters successfully printed.
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, num = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		num++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			num++;
		}
		current %= a;
	}
	__putchar('0' + current);
	num++;

	return (num);
}

/**
 * convert_number - Conversion function, similar to itoa.
 *
 * @num: The number to be converted.
 * @base: The base for the conversion.
 * @flags: Flags specifying conversion options.
 *
 * Return: A string representing the converted number.
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}

/**
 * remove_comments - A function that replaces the first occurrence of '#' with '\0' in a string.
 *
 * @buf: The address of the string to be modified.
 *
 * Return: Always returns 0.
 */

void remove_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
}
