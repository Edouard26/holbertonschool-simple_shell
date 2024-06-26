#include "shell.h"
/**
 * _strdup - string duplicate
 * @s: const char
 * Return: Always 0.
 */

char *_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *new_str = (char *)malloc(len);

	if (new_str == NULL)
		return (NULL);

	strcpy(new_str, s);

	return (new_str);
}
