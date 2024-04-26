#include "shell.h"
/**
 * exec - Executes an external command.
 *
 * @command: Array of strings representing the command and its arguments.
 * @av: Array of strings representing the command-line arguments.
 * @index: Index of the command in the shell's execution history.
 * Return: The exit status of the executed command.
 */
int exec(char **command, char **av, int index)

{
	pid_t child;
	int status;
	char *path;

	path = _path(command[0]);
	if (!path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], index, command[0]);
		free_array(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			free(path), path = NULL;
			free_array(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(command);
		free(path), path = NULL;
	}
	return (WEXITSTATUS(status));
}
