#include "shell.h"

/**
 * interactive - checks if the shell is in interactive mode
 * @info: a structure containing information about the shell
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a separator
 * @c: the character to check
 * @delim: a string containing separators
 *
 * Return: 1 if it's a separator, 0 if not
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if it's alphabetic, 0 if not
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string in the code to be converted
 *
 * Return: 0 if numbers are not present in the string,
 * convert number
 */
int _atoi(char *s)
{
	int x, s_count = 1, flag_count = 0, op;
	unsigned int r = 0;

	for (x = 0;  s[x] != '\0' && flag_count != 2; x++)
	{
		if (s[x] == '-')
			s_count *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag_count = 1;
			r *= 10;
			r += (s[x] - '0');
		}
		else if (flag_count == 1)
			flag_count = 2;
	}

	if (s_count == -1)
		op = -r;
	else
		op = r;

	return (op);
}
