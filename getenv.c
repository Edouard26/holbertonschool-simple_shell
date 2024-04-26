#include "shell.h"
/**
 * get_env - Retrieves the value of an environment variable.
 *
 * @variable: The name of the environment variable to retrieve.
 * Return: A dynamically allocated string containing the value of the variable.
 * Returns NULL if the variable is not found or
 * in case of memory allocation failure.
 */
char *get_env(char *variable)

{
	char *tmp, *value, *key, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);

		key = strtok(tmp, "=");

		if (key != NULL && strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");

			env = (value != NULL) ? _strdup(value) : NULL;

			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
