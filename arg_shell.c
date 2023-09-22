#include "shell.h"

 /**
 * **make_args - Split user input into an array of arguments
 *
 * @input: User input to be parsed into arguments
 *
 * Return: A null-terminated array of arguments
 */
char **make_args(char *input)
{
	char **args_, *arg_, *pos_, *delims_;
	int x, word_count;

	pos_ = NULL;
	delims_ = "\n\t \r\a";
	a = 0;
	word_count = wordcount(input);
	args_ = smart_alloc(sizeof(char *) * (word_count + 1));
	arg_ = tokenize(input, delims_, &pos_);
	while (arg_ != NULL)
	{
		args_[x] = arg_;
		if (args_[x][0] == '#')
			break;
		arg_ = tokenize(NULL, delims_, &pos_);
		x++;
	}
	args_[x] = NULL;
	return (args_);
}

/**
 * wordcount - Count words in a string
 *
 * @str: String to be analyzed
 *
 * Return: The number of words in @str
 */
int wordcount(char *str)
{
	int word_count, s, x;

	x = word_count = 0;
	s = OUT;
	while (str[x] != '\0')
	{
		switch (str[x])
		{
		case '\0':
		case ' ':
		case '\t':
		case '\n':
			if (s == IN)
			{
				s = OUT;
				word_count++;
			}
			x++;
			break;
		default:
			state = IN;
			x++;
		}
	}
	return (word_count);
}

 /**
 * check_arg- Compare the original first argument to a possibly new one
 *
 * @originalArg: The original first argument
 * @newArg: The argument that may have changed
 *
 * Return: 0 if they are the same, 1 if they are different
 */
int check_arg(char *firstarg, char *arg0)
{
	int p;

	p = 0;
	while (firstarg[p] != '\0')
		p++;
	if (_strncmp(firstarg, arg0, p) == 0)
		return (0);
	return (1);
}
