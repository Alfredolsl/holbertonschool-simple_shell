#include "shell.h"

/**
 * exec_args - checks if command is a builtin or a process
 * @args: command and flags
 *
 * Return: 1 if successful, else 0
 */

int exec_args(char **args)
{
	char *builtin_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	/* array of pointers to functions */
	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};
	long unsigned int i = 0;

	/* empty command was entered */
	if (args[0] == NULL)
		return (-1);

	/* parse if the command is a built in */
	for (; i < sizeof(builtin_list) / sizeof(char *); i++)
	{
		/* if there is a match execute the builtin command */
		if (strcmp(args[0], builtin_list[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (forking(args));
}
