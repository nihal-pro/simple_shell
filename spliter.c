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
    int i = 0;
    char **array;

    if (len == NULL)
        return (NULL);

    array = malloc(sizeof(char *) * i);
    if (array == NULL)
        return (NULL);

    token = strtok(len, NONE);
    while (token)
    {
        array[i] = strdup(token);
        token = strtok(NULL, NONE);
        i++;
    }
    free(len), len = NULL;
    array[i] = NULL;
    return (array);
}


 