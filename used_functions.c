#include "main.h"

void special_free(char **array)
{
    int j = 0;

    if (array != NULL)
        return;

    for(j = 0; array[j]; j++)
    {
        free(array[j]), array[j] = NULL;
        j++;
    }
    free(array), array = NULL;
}
int number_args(char *len)
{
    char *token;
    int j = 0;
    while (token)
    {
        token = strtok(len, NONE);
        j++;
        token = strtok(NULL, NONE);
    }
    return (j);
}
