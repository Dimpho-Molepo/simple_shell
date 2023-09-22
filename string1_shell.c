#include "shell.h"

/**
 * _strncmp - Compare two strings.
 *
 * @s1: The first string to compare with @s2.
 * @s2: The second string used for comparison with @s1.
 * @n: The length up to which the strings are compared.
 *
 * Return: An integer representing the difference
 * between the characters in @s1 and @s2 up to the specified length @n.
 */

int _strncmp(char *s1, char *s2, int n)
{
	char c, c1;

	while (n > 0)
	{
		c = *s1++;
		c1 = *s2++;
		if (c == '\0' || c != c1)
			return (c - c1);
		n--;
	}
	return (c - c1);
}

/**
 * str_concat - Combine two strings into a memory space.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the merged string.
 */

char *str_concat(char *s1, char *s2)
{
	char *c1, *ptr;
	int s1length, s2length;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1length = _strlen(s1);
	s2length = _strlen(s2);
	c1 = smart_alloc(s1length + s2length + 1);
	ptr = c1;
	while (*s1 != '\0')
	{
		*c1 = *s1;
		c1++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*c1 = *s2;
		c1++;
		s2++;
	}
	*c1 = '\0';
	return (ptr);
}


/**
 * *_strcpy - Copy the string from @src to the @dest buffer,
 * including the null terminator.
 *
 * @dest: Pointer to the buffer where the string will be copied.
 * @src: Pointer to the string that will be copied to the buffer.
 *
 * Return: A pointer to the @dest buffer.
 */

char *_strcpy(char *dest, char *src)
{
	int z;

	z = 0;
	for (z = 0; src[z] != '\0'; z++)
		dest[z] = src[z];
	dest[z] = '\0';
	return (dest);
}

