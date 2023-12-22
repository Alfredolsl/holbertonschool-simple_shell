#include "shell.h"

/**
 *
 */

void interactive_mode(void)
{
	char *line, **args;
	int status = -1;

	do {
		printf("hsh$ "); /* prompt */
		line = readline()
	
	} while (status == -1) 
}
