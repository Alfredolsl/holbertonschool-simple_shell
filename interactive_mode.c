#include "shell.h"

/**
 *
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
	
	} while (status == -1) 
}
