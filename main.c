#include "main.h"
/**
 * main - Entry point for the shell program
 * @ac : count of arguments
 * @av : arguments 
 * Return: 0 (success), or status of the non_interactive_mode
 */
int main (int ac, char **av)
{
   char *len = NULL;
    char **tokens;
    (void)ac;

    while (1)
    {
        len = _input_len();
        /*free(len);*/
        tokens = _spliter(len);
        _execute(tokens, av);
        /*if (tokens != NULL)
        {
            for (int i = 0; tokens[i] != NULL; i++)
            {
                printf("%s\n", tokens[i]);
            }
        }
        special_free(tokens);*/
    }
    return (0);

    /*cmnd = _execute(token);*/
}