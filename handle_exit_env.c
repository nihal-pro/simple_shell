#include "main.h"
/**
 * _builtin - Checks if a given command is a built-in shell command.
 * @my_command : A string representing the command to be checked.
 * Return: 0 in success
 */
int _builtin(char *my_command)
{
	int i;
	char *builtins = {"exit", "env",
		"setenv", "cd", NULL};

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(my_command[0], builtins[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - Handles the execution of built-in shell commands.
 * @my_command : A string representing the command to be checked.
 * @av : Unused parameter (shell name and arguments).
 * @status : Pointer to the exit status of the shell.
 * Return: void
 */
void handle_builtin(char **my_command, char **av, int *status)
{
	(void)av;

	if (_strcmp(my_command[0], "exit") == 0)
		shell_exit(my_command, &status);
	else if (_strcmp(my_command[0], "env") == 0)
		_env(my_command, &status);
}
/**
 * shell_exit - Exits the shell with the specified exit status.
 * @my_command : A string representing the command to be checked.
 * @status : Pointer to the exit status of the shell.
 * @argv: argummant
 * @idx: index
 * Return: Void
 */
void shell_exit(char **my_command, char **argv, int *status, int idx)
{
	int exit_value = *status;
	char *index, messag[] = ": exit: Illegal number: ";

	if (my_command[1])
	{
		if (positif_number(my_command[1]))
			exit_value = _atoi(my_command[1]);
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDEiRR_FILENO, ": ", 2);
			write(STDERR_FILENO, messag[], _strlen(messag));
			write(STDERR_FILENO, my_command[1], _strlen(my_command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			special_free(my_command);
			return;
		}
	}
	special_free(my_command);
	exit(exit_value);
}
/**
 * _env - Displays the environment variables to the standard output.
 * @my_command : A string representing the command to be checked.
 * @status : Pointer to the exit status of the shell.
 * Return: Void
 */
void _env(char **my_command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	special_free(my_command);
	(*status) = 0;
}
