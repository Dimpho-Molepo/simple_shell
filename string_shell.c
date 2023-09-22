#include "shell.h"

/**
 * _strlen - Calculate and return the length of a string.
 *
 * @s: The string for which to determine the length.
 *
 * Return: The length of the string @s.
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strdup - Create and return a pointer to a duplicated
 * copy of the string @str.
 *
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string;
 * NULL in case of insufficient memory.
 */

char *_strdup(char *str)
{
	char *c;
	int z, num;


	if (str == NULL)
		return (NULL);
	num = _strlen(str);
	c = smart_alloc((num + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);

	for (z = 0; z < num; z++)
	{
		c[z] = str[z];
	}
	c[z] = str[z];
	return (c);
}

/**
 * _strspn - Determine the length of a prefix substring in a string.
 *
 * @s: The string to search within.
 * @accept: The substring to compare the string with.
 *
 * Return: The number of bytes in the initial portion of @s
 * that match characters from @accept.
 */

int _strspn(char *s, const char *accept)
{
	int z, x, flag, size;

	z = flag = size = 0;
	while (s[z] && size == z)
	{
		for (x = 0; accept[x] && !flag; x++)
		{
			if (accept[x] == s[z])
			{
				size++;
				flag = 1;
			}
		}
		flag = 0;
		z++;
	}
	return (size);
}

/**
 * _strchr - Find the position of a character in a string.
 *
 * @s: Pointer to the string.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of @c in @s.
 */

char *_strchr(char *s, char c)
{
	int z;

	for (z = 0; s[z] != 0; z++)
		if (s[z] == c)
			return (s + z);
	if (s[z] == c)
		return (s + i);
	return (NULL);
}

/**
 * _strpbrk - Search the string @s for the first occurrence
 * of any characters from @accept
 *
 * @s: The string to be searched.
 * @accept: The string containing characters to search for within @s.
 *
 * Return: A pointer to the first matching character in @s from @accept,
 * or NULL if none are found.
 */

char *_strpbrk(char *s, const char *accept)
{
	int x, z;

	x = 0;
	while (s[x])
	{
		z = 0;
		while (accept[z])
		{
			if (accept[z] == s[x])
				return (s + x);
			z++;
		}
		x++;
	}
	return (NULL);
}

