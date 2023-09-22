#include "shell.h"

/**
 * _strncpy - Function for copying a string.
 *
 * @dest: The destination string where the copy will be placed.
 * @src: The source string to be copied from.
 * @n: The number of characters to be copied.
 *
 * Return: Returns the concatenated string.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *ptr = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (ptr);
}

/**
 * _strncat - Function for combining two strings.
 *
 * @dest: The first string to which the second string will be concatenated.
 * @src: The second string to be appended.
 * @n: The maximum number of bytes to be used for concatenation.
 *
 * Return: Returns the concatenated string.
 */

char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *ptr = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (ptr);
}

/**
 * _strchr - Finds the position of a character in a string.
 *
 * @s: The string to be searched.
 * @c: The character to locate within the string.
 *
 * Return: Returns a pointer to the memory area containing the string 's'.
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
