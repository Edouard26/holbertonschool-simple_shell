#include "shell.h"
/**
 * read_line - Reads a line of input from the user.
 *
 * Return: A pointer to the buffer containing the input line.
 *         Returns NULL on failure or when encountering EOF.
 */

char *read_line(void)
{
	ssize_t n;
	size_t len = 0;
	char *buf = NULL;

	if (isatty(STDIN_FILENO))

		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&buf, &len, stdin);

	if (n == -1)
	{
		free(buf), buf = NULL;
		return (NULL);
	}
	return (buf);
}
