#include "shell.h"

/**
 * get_location - gets file path location to execute command
 * @command - command to search its file path
 *
 * Return: char pointer to the path of the command
 */

char *get_location(char *command)
{
	char *path, *path_copy;
	char *path_token, *file_path;
	unsigned int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);

		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		/* if user inputs full file path, returns command */
		if (stat(command, &buffer) == 0)
			return (command);

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);

			/* v completes file path v */
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}

			path_token = strtok(NULL, ":");
		}
		free(path_copy);
		free(file_path);

		return (NULL);
	}
	return (NULL);
}
