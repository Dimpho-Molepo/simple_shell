#ifndef SHELL_MAIN_HEADER
#define SHELL_MAIN_HEADER
#define OUT 0
#define IN 1

/* --Global Variables-- */
extern char **environ;
int inchild;

/**
 * struct addresses - Structure representing
 * a node for storing a list of addresses.
 * @address: The address being stored in the node.
 * @next: A reference to the next node in the list.
 */

typedef struct addresses
{
	void *address;
	struct addresses *next;
} addr_t;

/**
 * struct builtins_s - Structure to store the names
 * and function pointers of built-in commands.
 * @name: The name of the built-in command.
 * @func: A pointer to the function to execute
 * when the name is provided as input.
 */

typedef struct builtins_s
{
	char *name;
	int (*func)();
} builtins_t;

/**
 * struct help_s - Structure for storing various descriptions
 * of built-in commands.
 * @name: The name of the specific built-in command
 * for which help is provided.
 * @func: The function responsible for displaying
 * help information for that command.
 */

typedef struct help_s
{
	char *name;
	void (*func)();
} help_t;

/* --Library Headers-- */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

/* --General Functions-- */
void loop(void);
char **make_args(char *input);
int wordcount(char *str);
char *tokenize(char *input, const char *delim, char **saveptr);
void output(char **args);
void execute(char **args);
void sighandler(int sig_num);
int check_arg(char *firstarg, char *arg0);

/* --Memory Functions-- */
void free_array(char **array);
void *smart_alloc(size_t size);

/* --Path Functions-- */
char **check_path(char **args);
char *path_concat(char *s1, char *s2);
char *_copypath(char *name);

/* --Builtin Functions-- */
int check_builtins(char **args, char *input);
int hosh_printenv(char **args);
int hosh_setenv(char **args);
int hosh_unsetenv(char **args);
int hosh_exit(char **args, char *input);
int hosh_help(char **args);

/* --Env Functions-- */
int _unsetenv(char *name);
char *_findenv(char *name);
int _addenv(char *newvar, char *name);

/* --Print Functions-- */
void _puts(char *str);
int _putchar(char c);

/* --String Functions-- */
char *_strdup(char *str);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strpbrk(char *s, const char *accept);
int _strspn(char *s, const char *accept);
int _strncmp(char *s1, char *s2, int n);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

/* --Math Functions-- */
int _atoi(char *str);

/* --Help Functions-- */
void help_exit(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_help(void);
void print_help(void);
#endif /* SHELL_MAIN_HEADER */

