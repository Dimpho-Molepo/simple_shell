#include "shell.h"

 /**
 * check_path - Search for the file in the PATH and replace
 * the command argument with the full file name if found.
 *
 * @args: Pointer array holding the command and all command arguments.
 *
 * Return: Pointer array to commands with the first command replaced if the
 * file was found, or the original commands if not found.
 */
char **check_path(char **args)
{
	char *filename, *delim, *pos, *path, *dir;
	struct stat st;

	pos = NULL;
	delim = ":";
	path = _copypath("PATH");
	if (path == NULL)
	{
		_puts("You have no PATH? What are you, crazy?\n");
		_exit(22);
	}
	dir = tokenize(path, delim, &pos);
	while (dir != NULL)
	{
		filename = path_concat(dir, args[0]);
		if (stat(filename, &st) == 0)
		{
			args[0] = filename;
			free(path);
			return (args);
		}
		dir = tokenize(NULL, delim, &pos);
		free(filename);
	}
	free(path);
	return (args);
}

 /**
 * path_concat - Combine two strings with a '/' in between.
 *
 * @s1: The first part of the new combined string.
 * @s2: The second part to attach to the end of the combined string.
 *
 * Return: Pointer to the new string.
 */
char *path_concat(char *s1, char *s2)
{
	char *s, *p;
	int s1len, s2len;

	s1len = s2len = 0;
	s1len = _strlen(s1);
	s2len = _strlen(s2);
	s = smart_alloc((s1len + s2len + 2) * sizeof(char));
	p = s;
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '/';
	s++;
	while (*s2 != '\0')
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (p);
}


 /**
 * _copypath- Find the PATH variable and create a duplicate of its value.
 *
 * @name: The name of the PATH variable.
 *
 * Return: The value of the PATH variable, or NULL if it can't be found.
 */
char *_copypath(char *name)
{
	char **envp, *path;
	int len, i;

	i = 0;
	envp = environ;
	len = _strlen(name);
	while (envp[i] != NULL)
	{
		if (_strncmp(envp[i], name, len) == 0)
		{
			path = _strdup(&envp[i][len + 1]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
