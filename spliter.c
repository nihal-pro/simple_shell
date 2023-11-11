#include "main.h"
/**
 * _spliter - split len 
 * 
 * Description: Spliting the command,
 * Return: token (success),
 */
char **_spliter(char *len)
{
    char *token = NULL;
    int i = 0;
    char **array = NULL;

    if (len == NULL)
        return NULL;
    token = strtok(len, NONE);
    array = malloc(sizeof(char *) * 1024);
    while(token)
    {
        if (array == NULL)
        {
            len = NULL;
            free(len);
            return NULL;
        }
        array[i] = token;
        token = strtok(NULL, NONE);
        i++;
    }
    free (len), len = NULL; 
    return (array);
    array[i] = NULL;
    free(array);
}