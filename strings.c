#include "main.h"
/**
 * _strdup - Duplicates a string
 * @ssd: The source string to duplicate
 *
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
