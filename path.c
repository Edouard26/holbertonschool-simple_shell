#include "shell.h"
/**
 * _path - Locates the full path of an executable command.
 *
 * @command: The command to find the full path for.
 * Return: A dynamically allocated string containing
 * the full path of the command.
 * Returns NULL if the command is not found
 * or in case of memory allocation failure.
 */
char *_path(char *command)
{
	char *env, *path, *cmd;
	struct stat buf;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &buf) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	env = get_env("PATH");
	if (!env)
		return (NULL);
	path = strtok(env, ":");
	while (path)
	{
		cmd = malloc(strlen(path) + strlen(command) + 2);
		if (cmd != NULL)
		{
			snprintf(cmd, strlen(path) + strlen(command) + 2, "%s/%s", path, command);
			if (stat(cmd, &buf) == 0)
			{
				free(env);
				return (cmd);
			}
			free(cmd);
			path = strtok(NULL, ":");
		}
		else
		{
			free(env);
			return (NULL);
		}
	}
	free(env);
	return (NULL);
}
