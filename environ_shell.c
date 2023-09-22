#include "shell.h"

 /**
 * _myenv - Print the current environment variables
 * @info: Structure containing potential arguments
 * Return: Always returns 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

 /**
 * _getenv - Retrieve the value of an environment variable
 * @info: Struct containing potential arguments
 * @name: Variable name
 * Return: The value of the variable or NULL if not found
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *n = info->env;
	char *pointer;

	while (n)
	{
		pointer = starts_with(n->str, name);
		if (pointer && *pointer)
			return (pointer);
		n = n->next;
	}
	return (NULL);
}

 /**
 * _mysetenv - Set or modify an environment variable
 * @info: Struct containing potential arguments
 * Return: 0 on success, 1 on error
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

 /**
 * _myunsetenv - Remove an environment variable
 * @info: Struct containing potential arguments
 * Return: 0 on success, 1 on error
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

 /**
 * populate_env_list - Populate the environment linked list from 'environ'
 * @info: Struct containing potential arguments
 * Return: 0 on success, 1 on error
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
