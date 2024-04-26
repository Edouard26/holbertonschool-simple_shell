#include "shell.h"
/**
 * _str - Tokenizes a string into an array of strings.
 *
 * @line: The string to be tokenized.
 * Return: An array of strings (tokens).
 *         Returns NULL on failure or when @line is NULL.
 */

char **_str(char *line)
{
	char *token, *delim = " \t\n", *tmp = NULL, **command = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, delim);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
