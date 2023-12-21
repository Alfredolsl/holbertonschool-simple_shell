#include "shell.h"

/**
 * execmd - executes input
 * @argv: argument vector containing command
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;

	if (argv)
	{
		command = argv[0];

		actual_cmd = get_location(command);

		if (actual_cmd == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			return;
		}

		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
}
