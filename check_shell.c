#include "shell.h"

/**
 * check_builtins - Check the command if it is a builtin function
 * @args: Array storing command and all its arguments
 * @input: The input from user
 *
 * Return: 1 for success or -1 for failure
 */
int check_builtins(char **args, char *input)
{
	builtins_t builtins[] = {
		{"exit", hosh_exit},
		{"env", hosh_printenv},
		{"unsetenv", hosh_unsetenv},
		{"setenv", hosh_setenv},
		{"help", hosh_help},
		{NULL, NULL}
	};
	int i, len;

	len = _strlen(args[0]);
	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strncmp(args[0], "exit", 4) == 0)
			return (builtins[0].func(args, input));
		if (_strncmp(args[0], builtins[i].name, len) == 0)
			return (builtins[i].func(args));
	}
	return (-1);
}
