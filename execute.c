#include "main.h"
/**
 * _execute - Executes a command specified
 * by the token array in a child process.
 * @token : array of strings representing
 * the command and its arguments.
 * @argv : array of strings representing
 * the command-line arguments.
 * Return: Returns the exit status of the child process
 */
int _execute(char **token, char **argv)
{
	int status = 0;
	pid_t pid;

	if (token == NULL || token[0] == NULL)
	{
		/*Handle the case where token is NULL or empty*/
		free(token);
		/*Or any other appropriate error code*/
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(token[0], token, environ) == -1)
		{
			perror(argv[0]);
			special_free(token);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		special_free(token);
	}
	return (WEXITSTATUS(status));/*handle exit status*/
}

