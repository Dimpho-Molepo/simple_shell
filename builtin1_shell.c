#include "shell.h"


/**
 * _myhistory - Display command history with line numbers
 * @info: Structure containing potential arguments
 *
 * Return: Always returns 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}


/**
 * unset_alias - Unset an alias by removing it from the alias list
 * @info: Structure containing alias list
 * @str: Alias string to unset
 *
 * Return: 0 for success, 1 for error
 */
int unset_alias(info_t *info, char *str)
{
	char *pointer, character;
	int ret_count;

	pointer = _strchr(str, '=');
	if (!pointer)
		return (1);
	character = *pointer;
	*pointer = 0;
	ret_count = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pointer = character;
	return (ret_count);
}

/**
 * set_alias - Set an alias by adding it to the alias list
 * @info: Structure containing alias list
 * @str: Alias string to set
 *
 * Return: 0 for success, 1 for error
 */
int set_alias(info_t *info, char *str)
{
	char *pointer;

	pointer = _strchr(str, '=');
	if (!pointer)
		return (1);
	if (!*++pointer)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Manage aliases by setting, unsetting, or printing them
 * @node: Structure containing alias list and arguments
 *
 * Return: 0 for success
 */
int print_alias(list_t *node)
{
	char *pointer = NULL;
	char *x = NULL;

	if (node)
	{
		pointer = _strchr(node->str, '=');
		for (x = node->str; x <= pointer; x++)
			_putchar(*x);
		_putchar('\'');
		_puts(pointer + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Manage aliases by setting, unsetting, or printing them
 * @info: Structure containing alias list and arguments
 *
 * Return: 0 for success
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *pointer = NULL;
	list_t *n = NULL;

	if (info->argc == 1)
	{
		n = info->alias;
		while (n)
		{
			print_alias(node);
			n = n->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		pointer = _strchr(info->argv[x], '=');
		if (pointer)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}
