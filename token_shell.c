#include "shell.h"

/**
 * tokenize - Extract the next token from the @input string;
 * using the specified delimiter.
 *
 * @input: The string to tokenize.
 * @delim: The delimiter string.
 * @saveptr: A pointer for saving the current position.
 *
 * Return: The next token(tkn) found in the @input string.
 */

char *tokenize(char *input, const char *delim, char **saveptr)
{
	char *tkn;
	int z;

	z = 0;
	if (input == NULL)
		input = *saveptr;
	input += _strspn(input, delim);
	if (*input == '\0')
	{
		*saveptr = input;
		return (NULL);
	}
	tkn = input;
	input = _strpbrk(input, delim);
	if (input == NULL)
	{
		while (tkn[z] != '\0')
			z++;
		*saveptr = tkn + z;
	}
	else
	{
		*input = '\0';
		*saveptr = input + 1;
	}
	return (tkn);
}

