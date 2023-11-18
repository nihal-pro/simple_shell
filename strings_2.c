#include "main.h"
/**
 * _atoi - Convert an integer to a string.
 * @x: The integer to be converted.
 *
 * Description:This function converts an integer to a string representation
 *
 * Return: A dynamically allocated string containing the integer
 *         representation.
 */
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
/**
 * reverse_str - Reverse a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 *
 * Description:This function reverses the characters in a given string.
 */
void reverse_str(char *str, int len)
{
	int start = 0, end = len - 1;
	char tmp;

	while (start < end)
	{
		len = _strlen(str);

		/*Swap characters at start and end indices*/
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;

		/*Move indices towards the center*/
		start++;
		end--;
	}
}
