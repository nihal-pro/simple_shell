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
    /*char *token;*/
    /*int cmnd;*/
    (void)ac;
    (void)av;

    while (1)
    {
        len = _input_len();
        /*token = spliter(len);
        cmnd = _execute(token);*/
        free(len);
    }
    return (0);
}