#include "main.h"
/**
 * main - Entry point for the shell program
 * @ac : count of arguments
 * @av : arguments 
 * Return: 0 (success), or status of the non_interactive_mode
 */
/*int main (int ac, char **av)
{
   char *len = NULL;
    char **tokens;
    int status, idx = 0;
    (void)ac;

    while (1)
    {
        len = _input_len();
        if (len == NULL)
            return (status);
        free(len);
        idx++;
        tokens = _spliter(len);


        status = _execute(tokens, av, idx);
        if (tokens != NULL)
        {
            for (int i = 0; tokens[i] != NULL; i++)
            {
                printf("%s\n", tokens[i]);
            }
        }
        special_free(tokens);
    }
    cmnd = _execute(token);

}*/

int main (int ac, char **av)
{
    char *len = NULL;
    char **tokens;
    /*int status = 0, idx = 0;*/
    int status;
    (void)ac;

    while (1)
    {
        len = _input_len();
        if (len == NULL)
        {
            if (isatty(STDIN_FILENO) == 1)
                write(1, "\n", 1);
            return (status);
        }

        tokens = _spliter(len);
        status = _execute(tokens, av);
    }
}