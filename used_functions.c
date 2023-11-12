#include "main.h"

void special_free(char **array)
{
    int j = 0;

    if (array != NULL)
        return;

    while (array[j] != NULL)
    {
        free(array[j]);
        j++;
    }
    free(array);
}