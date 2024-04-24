#include "shell.h"

/**
 * print_environment - Prints the environment variables
 */

void print_environment(void)
{
	extern char **environ;
	char **i = environ;

	while (*i != NULL)
	{
		printf("%s\n", *i);
		i++;
	}
}

/**
 *_getenv - get a variable environment
 *@env: list of variables environment
 *@name: name of get
 *Return: Variable value of environment or NULL
 */
char *_getenv(char **env, const char *name) {
	int i = 0;

	while (env[i] != NULL) {
		if (strncmp(env[i], name, strlen(name)) == 0 && (env[i])[strlen(name)] == '=') {
			return (env[i] + strlen(name) + 1);
		}
		i++;
	}
	return (NULL);

}
