#include "shell.h"

 /**
 * _unsetenv - Unset an environment variable.
 *
 * name: The name of the variable to unset.
 *
 * Return: 0 for success, -1 for failure
 */
int _unsetenv(char *name)
{
	char **x;
	int width;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	width = _strlen(name);
	x = environ;
	while (*ep != NULL)
	{
		if (_strncmp(*x, name, width) == 0 && (*x)[width] == '=')
			while (*x != NULL)
			{
				*x = *(x + 1);
				x++;
			}
		else
			x++;
	}
	return (0);
}

 /**
 * _findenv - Get a pointer to an environment variable.
 *
 * name: The name of the variable to find.
 *
 * Return: Pointer to the variable if it exists, or NULL if it doesn't.
 */
char *_findenv(char *name)
{
	char **wrap;
	int width;

	wrap = environ;
	width = _strlen(name);
	while (*wrap != NULL)
	{
		if (_strncmp(*wrap, name, width) == 0)
			return (*wrap);
		wrap++;
	}
	return (*wrap);
}

 /**
 * _addenv - Add or modify an environment variable.
 *
 * @newvar: The variable and its value.
 * @name: The name of the variable to add or modify.
 *
 * Return: 0 if success, -1 if failure
 */
int _addenv(char *newvar, char *name)
{
	char **enviro_new, **n_h;
	size_t f;

	if (_findenv(name) == NULL)
	{
		for (f = 0; environ[f] != NULL; f++)
			;
		enviro_new = smart_alloc(sizeof(char *) * (f + 2));
		newhead = enviro_new;
		f = 0;
		while (*environ != NULL)
		{
			*enviro_new = *environ;
			enviro_new++;
			environ++;
		}
		*enviro_new = newvar;
		enviro_new++;
		*enviro_new = NULL;
		environ = n_h;
		return (0);
	}
	else
		return (-1);
	return (0);
}
