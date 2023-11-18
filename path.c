#include "main.h"
/**
 * _getpath - Searches for the full path of a given command.
 * @command : string representing the command to find the full path for.
 * Return: NULL
 */
char *_getpath(char *command)
{
	char *path_env, *fulltoken, *DIREC;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)/*argument already path*/
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
		return (NULL);
	} path_env = _getenv("PATH");/*allocate memory - echo $PATH*/
	if (!path_env)/*in case unset path*/
		return (NULL);
	DIREC = strtok(path_env, ":");
	while (DIREC)
	{
		fulltoken = malloc(_strlen(DIREC) + _strlen(command) + 2);
		if (!fulltoken)
		{
			free(fulltoken);
			return (NULL);
		}
		else
		{
			_strcpy(fulltoken, DIREC);
			_strcat(fulltoken, "/");
			_strcat(fulltoken, command);
			if (stat(fulltoken, &st) == 0)
			{
				free(path_env);
				return (fulltoken);
			}
			free(fulltoken), fulltoken = NULL;
			DIREC = strtok(NULL, ":");
		}
	} free(path_env);
	return (NULL);/*if give me a direct dont exist*/
}
