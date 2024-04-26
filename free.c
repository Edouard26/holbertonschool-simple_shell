#include "shell.h"
/**
 * free_array - Frees a dynamically allocated 2D array of strings.
 *
 * @command: The 2D array of strings to be freed.
 */
void free_array(char **command)
{
	int i;

	if (!command)
		return;

	for (i = 0; command[i]; i++)

		free(command[i]), command[i] = NULL;

	free(command), command = NULL;
}
