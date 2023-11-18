#include "main.h"
/**
 * _strcat - function that concatenates
 *          two strings.
 * @dest: pointer to destnation input
 * @src: pointer to source input
 *Return: pointer to resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int c2, c = 0;

	while (dest[c])
		c++;
	for (c2 = 0; src[c2]; c2++)
		dest[c++] = src[c2];
	dest[c] = '\0';
	return (dest);
}
/**
 *_strcpy - copies the string pointed to by src to dest.
 *@src: pointer to string.
 *@dest: string coped.
 *Return: return value.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}

