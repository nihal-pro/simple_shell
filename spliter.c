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
    int i = 0, argc = 0;
    char **array = NULL;

    if (len == NULL)
        return (NULL);

    argc = number_args(len);
    if (argc <= 0)
        return NULL;
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

