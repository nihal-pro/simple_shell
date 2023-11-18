#include "main.h"
/**
 * special_free - frees memory allocated for a dynamically
 * allocated array of strings.
 * @array : A pointer to an array of strings (char**.
 * Return: Void
 */
void special_free(char **array)
{
	int j = 0;

	if (array != NULL)
	{
		for (j = 0; array[j]; j++)
		{
			free(array[j]), array[j] = NULL;
			free(array), array = NULL;
		}
	}
}
/**
 * _getenv - get the value for any environment variable
 * @env : environment variable
 * Return: return an string of full path.
 */
char *_getenv(char *env)
{
	char *dep, *key, *val, *value;
	int i;

	for (i = 0; environ[i]; i++)
	{
		dep = _strdup(environ[i]);/*allocate memory*/
		key = strtok(dep, "=");
		if (_strcmp(key, env) == 0)
		{
			val = strtok(NULL, " \n");
			value = _strdup(val);
			free(dep);
			return (value);
		}
		free(dep), dep = NULL;
	}
	return (NULL);
}
/**
 * handle_error - Prints an error message
 * to STDERR when a command is not found.
 * @shell_name : the name of environment variable
 * @comnd : The command that was not found.
 * @INDEX : The index corresponding to the command.
 * Return: Void
 */
void handle_error(char *shell_name, char *comnd, int INDEX)
{
	char *index, *message = ": not found\n";

	/*write n'accepte pas integer il faut convertir en ASCI*/
	index = _atoi(INDEX);
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comnd, _strlen(comnd));
	write(STDERR_FILENO, "message ", _strlen(message));
	free(index);
}




