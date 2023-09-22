#include "shell.h"

/**
 * main - start shell
 *
 * @ac: counts the number of arg
 * @av: list of arguments
 * @env: environment
 *
 * Return: 0 if success, -1 if failure
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	(void)av;
	loop();
	return (0);
}

/**
 * loop - prompt the shell loop
 *
 * Return: nothing
 */
void loop(void)
{
	char *takein, **arguments, *arg1;
	int counter;
	size_t width;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	width = 0;
	counter = 0;
	takein = NULL;
	while (1)
	{
		inchild = 0;
		_puts("Hosh$ ");
		if (getline(&takein, &width, stdin) != -1)
		{
			if (takein[0] != '\n' && takein[0] != '#')
			{
				arguments = make_args(takein);
				arg1 = args[0];
				if (check_builtins(arguments, takein) == -1)
				{
					inchild = 1;
					output(arguments);
				}
				if (check_arg(arg1, arguments[0]) == 0)
					free(arguments);
				else
					free_array(arguments);
				counter++;
			}
		}
		else
		{
			free(takein);
			_putchar('\n');
			_exit(0);
		}
	}
}

/**
 * sighandler - output the right message when control+c is pressed
 * @sig_num:variable that is unused
 */
void sighandler(int sig_num)
{
	(void)sig_num;
	if (inchild == 0)
		_puts("\nHosh$ ");
	signal(SIGINT, sighandler);
}
