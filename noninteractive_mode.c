#include "shell.h"

/**
 * noninteractive_mode - enters the shell in non-interactive mode
 */

void noninteractive_mode(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = readstream();
		args = splitline(line); /* tokenizes line */
		status = exec_args(args);

		free(line);
		free(args);

		if (status >= 0)
			exit(status);

	}while (status == -1);
}
