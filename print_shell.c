#include "shell.h"

/**
 * _puts - Outputs a string, followed by a newline,
 * to the standard output (stdout).
 *
 * @str: Pointer to the string to be printed.
 */

void _puts(char *str)
{
	int num = 0;

	while (*(str + num) != '\0')
	{
		_putchar(*(str + num));
		num++;
	}
}

/**
 * _putchar - Outputs the character 'c' to the standard output (stdout).
 *
 * @c: The character to be written.
 *
 * Return: Returns 1 on success.
 * If an error occurs, it returns -1 and sets the appropriate errno.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

