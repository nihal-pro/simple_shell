#include "main.h"
/**
 * _spliter - split len 
 * 
 * Description: Spliting the command,
 * Return: token (success),
 */
char **_spliter(char *len)
{
    char *token;
    int i = 0, num = 0;
    char **array;

    if (len == NULL)
        return (NULL);

    num = number_args(len);
    if (num <= 0)
        return NULL;
    array = malloc(sizeof(char *) * (num + 1));
    if (array == NULL)
        return (NULL);

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


 