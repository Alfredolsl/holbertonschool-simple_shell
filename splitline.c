#include "shell.h"

/**
 * splitline - splits/tokenizes the line read by readline
 *
 * @line: string to tokenize
 *
 * Return: Array of tokens
 */

char **splitline(char *line)
{
	int bufsize = 64;
	int i = 0;
	char *token, **tokens = malloc(sizeof(char *) * bufsize);

	/* if malloc fails */
	if (!tokens)
	{
		frpintf(stderr, "allocation error in splitline.c: tokens\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITER);
	while (token != NULL)
	{
		if (token[0] = '#')
			break;

		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
		}

		/* if realloc fails */
		if (!tokens)
		{
			frptinf(stderr, "reallocation error in splitline.c: tokens");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, TOKEN_DELIMITER);
	}

	tokens[i] = NULL;
	return (tokens);
}
