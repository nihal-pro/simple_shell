#include "main.h"

void special_free(char **array)
{
   int j = 0;

    if (array != NULL)
    {
        for (j = 0; array[j]; j++)
        {
            free(array[j]), array[j] = NULL;
        }
        free(array), array = NULL;
    }
}
int number_args(char *len)
{
    char *token = NULL, *dep = NULL;
    int j = 0;

    dep = _strdup(len);
    if (dep == NULL)
        return (-1);

    token = strtok(dep, NONE);
    while (token)
    {
        j++;
        token = strtok(NULL, NONE);
    }
    free(dep), dep = NULL;
    return (j);
}
