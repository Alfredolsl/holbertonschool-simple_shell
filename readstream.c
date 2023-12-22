#include "shell.h"

/**
 * read_stream - read a line from the stream
 *
 * Return: pointer to the read line
 */

char *readstream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in readstream.c");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		/* reads first char from stream */
		character = getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = character;

		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in readstream.c");
				exit(EXIT_FAILURE);
			}
		}
	}
}
