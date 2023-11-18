 #include "main.h"
/**
 * _spliter - Split a string into an array of tokens.
 * @len: The string to be split.
 *
 * Description: This function takes a string and splits it into tokens,
 * calculates the number of tokens in the string, allocates
 * memory for an array of strings, and copies each token into the array
 *
 * Return: An array of strings (tokens), or NULL if memory allocation fails
 *         or if the input string is NULL or empty.
 */
char **_spliter(char *len)
{
	char *token = NULL;
	int i = 0, argc = 0;
	char **array = NULL;

	if (!len)
		return (NULL);
	argc = number_args(len);
	if (argc <= 0)
		return (NULL);
	array = malloc(sizeof(char *) * (argc + 1));
	if (!array)
	{
		free(len);
		return (NULL);
	}
	token = strtok(len, NONE);
	while (token)
	{
		array[i] = _strdup(token);
		i++;
		token = strtok(NULL, NONE);
	}
	free(len), len = NULL;
	array[i] = NULL;
	return (array);
}

