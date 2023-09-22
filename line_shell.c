#include "shell.h"

/**
 * input_buf - Buffers chained commands.
 *
 * @info: The parameter structure.
 * @buf: The address of the buffer.
 * @len: The address of the length variable.
 *
 * Return: The number of bytes read.
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t t = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		t = getline(buf, &len_p, stdin);
#else
		t = _getline(info, buf, &len_p);
#endif
		if (t > 0)
		{
			if ((*buf)[t - 1] == '\n')
			{
				(*buf)[t - 1] = '\0';
				t--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = t;
				info->cmd_buf = buf;
			}
		}
	}
	return (t);
}

/**
 * get_input - Retrieves a line of text without the newline character.
 *
 * @info: The parameter structure.
 *
 * Return: The number of bytes read.
 */

ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t a, b, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		b = a;
		p = buf + a;

		check_chain(info, buf, &b, a, len);
		while (b < len)
		{
			if (is_chain(info, buf, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= len)
		{
			a = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * read_buf - Reads data into a buffer.
 *
 * @info: The parameter structure.
 * @buf: The buffer to store the data.
 * @i: The size of the buffer.
 *
 * Return: The result 't'.
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t t = 0;

	if (*i)
		return (0);
	t = read(info->readfd, buf, READ_BUF_SIZE);
	if (t >= 0)
		*i = t;
	return (t);
}

/**
 * _getline - Retrieves the next line of input from STDIN.
 *
 * @info: The parameter structure.
 * @ptr: The address of a pointer to a buffer, either preallocated or NULL.
 * @length: The size of the preallocated 'ptr' buffer, if it's not NULL.
 *
 * Return: The result 't'.
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, len;
	size_t k;
	ssize_t r = 0, t = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		t = *length;
	if (a == len)
		a = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + a, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, t, t ? t + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (t)
		_strncat(new_p, buf + a, k - a);
	else
		_strncpy(new_p, buf + a, k - a + 1);

	t += k - a;
	a = k;
	p = new_p;

	if (length)
		*length = t;
	*ptr = p;
	return (t);
}

/**
 * sigintHandler - Handles the blocking of the Ctrl-C signal.
 *
 * @sig_num: The signal number.
 *
 * Return: Void.
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
