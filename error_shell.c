#include "shell.h"

/**
 * _eputs - Displays an input string
 *
 * @str: The string to be shown on the screen
 *
 * Return: None
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchar - Outputs the character 'c' to the standard error stream (stderr).
 *
 * @c: The character to be written to stderr.
 *
 * Return: Returns 1 on success.
 * If an error occurs, it returns -1 and sets the appropriate errno.
 */

int _eputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * _putfd - Outputs the character 'c' to the specified file descriptor (fd).
 *
 * @c: The character to be written to the specified file descriptor.
 * @fd: The file descriptor to which 'c' is written.
 *
 * Return: Returns 1 on success.
 * If an error occurs, it returns -1 and sets the appropriate errno.
 */

int _putfd(char c, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * _putsfd - Displays an input string to a specified file descriptor (fd).
 *
 * @str: The string to be written to the specified file descriptor.
 * @fd: The file descriptor to which 'str' is written.
 *
 * Return: Returns the count of characters successfully written.
 */

int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}
