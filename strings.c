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

int _strcmp (const char *s1, const char *s2)
{
	while ( *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++; 
	}
	return (*s1 - *s2);
}

int _strlen (const char *str)
{
	int cmpt = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '\0')
			cmpt ++;
	}
	return (cmpt);
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

/**
 * _strcat - function that concatenates
 *          two strings.
 *
 * @dest: pointer to destnation input
 * @src: pointer to source input
 *
 * Return: pointer to resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int c, c2;

	c = 0;
	/*find the size of dest array*/
	while (dest[c])
		c++;

	for (c2 = 0; src[c2]; c2++)
		dest[c++] = src[c2];
	dest[c] = '\0';
	return (dest);
}


char *_atoi(int x)
{
	char buffer[20];
	int j = 0;

	if (x == 0)
		buffer[j++] = '0';
	else
	{
		while (x > 0)
		{
			buffer[j++] = (x % 10) + '0';
			x /= 10;
		}
	}
	buffer[j] = '\0';
	reverse_str(buffer, j);

	
	return (_strdup(buffer));
}

void reverse_str(char *str, int len)
{
	int start = 0, end = len - 1;
    len = _strlen(str);
	char tmp;

   	while (start < end) 
	{
        /*Swap characters at start and end indices*/
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        /*Move indices towards the center*/
        start++;
        end--;
    }
}





	