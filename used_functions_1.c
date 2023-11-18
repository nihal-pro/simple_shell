#include "main.h"
/**
 * print - Print a string to the standard output.
 * @str: The input string to be printed.
 *
 * Description: This function takes a string (@str) as input
 * printing it to the standard output using the write system call.
 *
 * Return: The same input string that was printed.
 */
char *print(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		write(1, &str[i], 1);
	}
	return (str);
}
/**
 * number_args - Count the number of tokens in a string.
 * @len: The input string to be tokenized.
 *
 * Description: This function takes a string (@len) as input, duplicates it,
 * and then tokenizes the duplicated string to count the number of tokens
 * Return: The number of tokens found in the input string.
 */
int number_args(char *len)
{
	char *token = NULL, *dep = NULL;
	int j = 0;

	dep = _strdup(len);
	token = strtok(dep, NONE);
	if (!token)
	{
		free(len), len = NULL;
		free(dep), dep = NULL;
		return (0);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, NONE);
	}
	free(dep), dep = NULL;
	return (j);
}
/**
 * positif_number - verifeying the sign of the number.
 * @str: The input string.
 *
 * Description: This function checks if the number is positif
 * Return: 1 if number is positif
 */
int positif_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _itoa - Convert to integer.
 * @str: The input string.
 *
 * Description: This function takes a string to convert it to integer
 * Return: number converti.
 */
int _itoa(char *str)
{
	int i, num = 0;

	for (i = 0; str[0]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
