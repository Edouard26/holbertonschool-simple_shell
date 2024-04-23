#include "shell.h"

void execute_command(char *args[]) 
{
	pid_t pid; 
	char *path;
	char *dir;
	int status;

	path = getenv("PATH");
	pid = fork();
	if (pid == -1) 
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} 

	else if (pid == 0) 
	{
		dir = strtok(path, ":");
		while (dir != NULL) 
		{


			strcpy(path, dir);
			strcat(path, "/");
			strcat(path, args[0]);

			if (access(path, X_OK) == 0) 
			{

				execve(path, args, NULL);
				perror(args[0]);
				_exit(EXIT_FAILURE);
			}
			dir = strtok(NULL, ":");
		}

		fprintf(stderr, "%s: command not found\n", args[0]);
		_exit(EXIT_FAILURE);
	} 
	else 
	{
		waitpid(pid, &status, 0);
	}
}
