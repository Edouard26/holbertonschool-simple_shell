#include "shell.h"

/**
 * command_exists - Checks if a command exists in the PATH
 * @command: The command to check
 *
 * Return: 1 if the command exists, 0 otherwise
 */

int command_exists(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char command_path[MAX_COMMAND_LENGTH];

		strcpy(command_path, dir);
		strcat(command_path, "/");
		strcat(command_path, command);
		
		if (access(command_path, X_OK) == 0)

		{
			printf("%s\n", command_path);
			free(path_copy);
			return (1);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}
