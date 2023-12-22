#include "shell.h"

/**
 * interactive_mode - enters the shell in interactive mode
 */

void interactive_mode(void)
{
	char *line, **args;
	int status = -1;

	do {
		printf("hsh$ ");
		line = readline();
		args = splitline(line);
		status = exec_args(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	
	} while (status == -1) 
}
