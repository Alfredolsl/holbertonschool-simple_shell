#include "shell.h"

/**
 * execmd - executes input
 * @argv: argument vector containing command
 */

void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
			perror("Error");
	}
}
