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
    token = strtok(dep, NONE);
    if (!token)
    {
        free(len), len = NULL;
        free(dep), dep = NULL;
        return (0);
    }
    while (token)
    {
        j++;
        token = strtok(NULL, NONE);
    }
    free(dep), dep = NULL;

    return (j);
}
/* $handle environnement of PATH$ */
char *_getenv(char *env)
{
    char *dep, *key, *val, *value;

    for (int i = 0; environ[i]; i++)
    {
        dep = _strdup(environ[i]);/*allocate memory*/
        key = strtok(dep, "=");
        if (_strcmp(key, env) == 0)
        {
            val = strtok(NULL, " \n");
            value = _strdup(val);       
            free (dep);
            return (value);
        }
        free (dep), dep = NULL;
    }
    return (NULL);
}

void handle_error(char *shell_name, char *comnd, int INDEX)
{
    char *index, *message = ": not found\n"; /*write n'accepte pas integer il faut convertir en ASCI*/

    index = _atoi(INDEX);
    write(STDERR_FILENO, shell_name, _strlen(shell_name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(shell_name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, comnd, _strlen(comnd));
    write(STDERR_FILENO, "message ", _strlen(message));
    /*free(index)*/


}
