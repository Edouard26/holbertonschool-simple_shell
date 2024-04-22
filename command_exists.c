#include "shell.h"

/**
 * command_exists - Checks if a command exists in the PATH
 * @command: The command to check
 *
 * Return: 1 if the command exists, 0 otherwise
 */

int command_exists(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char command_path[MAX_COMMAND_LENGTH];
		snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (1);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}
