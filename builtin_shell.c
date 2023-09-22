#include "shell.h"

/**
 * _myexit - Exit the shell
 * @info: Pointer to the info structure
 * Return: -2 to indicate exit
 */
int _myexit(info_t *info)
{
	int scan_exit;

	if (info->argv[1])
	{
		scan_exit = _erratoi(info->argv[1]);
		if (scan_exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - Change the current directory
 * @info: Pointer to the info structure
 * Return: 0 on success, 1 on error
 */
int _mycd(info_t *info)
{
	char *a;
	char *dir;
	char buffer[1024];
	int chdir_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - Display help information
 * @info: Pointer to the info structure
 * Return: 0 on success
 */
int _myhelp(info_t *info)
{
	char **argument_array;

	argument_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argument_array);
	return (0);
}
