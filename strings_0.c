#include "main.h"
/**
 * _strdup - Duplicates a string
 * @ssd: The source string to duplicate
 * *
 * Return: Returns a pointer(str)
 */
char *_strdup(const char *ssd)
{
	char *str;
	char *p;
	int i = 0;

	while (ssd[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*ssd)
		*p++ = *ssd++;
	*p = '\0';
	return (str);
}
/**
 * _strcmp - Compare two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Description:
 * This function compares two strings character by character.
 * Return: An integer indicating the result of the comparison.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strlen - Calculate the length of a string.
 * @str: The string for which to calculate the length.
 *
 * Description:
 * This function calculates and returns the length of a given string.
 *
 * Return: An integer representing the length of the string.
 */
int _strlen(const char *str)
{
	int i, cmpt = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != '\0')
			cmpt++;
	}
	return (cmpt);
}
