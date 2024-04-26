#include "shell.h"
/**
 * main - Entry point for the custom shell program.
 *
 * @ac: Number of arguments (unused in this context).
 * @av: Array of command-line arguments.
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, command_number = 0;

	while (1)
	{
		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command_number++;

		command = _str(line);

		if (!command)
			continue;

		if (built_in(command) == 1)
			handle_built_in(command, &status);
		else
			status = exec(command, av, command_number);
	}
	return (0);
}
