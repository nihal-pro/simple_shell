#include "main.h"

/*int _execute(char **token, char **argv, int inx)
{
    int status = 0;
    pid_t pid;
    char *my_command;

    my_command = _getpath(token[0]);
    if (my_command)
    {
        handle_error(argv[0], token[0], inx);
        special_free(token);
        return (127);
    }

    pid = fork();
    if(pid == EOF)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(pid == 0)
    {
        if(execve(my_command, token, environ) == -1)
        {
            perror(argv[0]);
            free (my_command); my_command = NULL;
            special_free(token);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        special_free(token);
        free (my_command); my_command = NULL; 
    }


    return (WEXITSTATUS(status));  handle exit status
}*/

int _execute(char **token, char **argv)
{
    int status = 0;
    pid_t pid;
    /*char *my_command;*/

   /* my_command = _getpath(token[0]);
    if (my_command)
    {
        handle_error(argv[0], token[0], inx);
        special_free(token);
        return (127);
    }*/

    pid = fork();
    if(pid == 0)
    {
        if(execve(token[0], token, environ) == -1)
        {
            perror(argv[0]);
            /*free (my_command); my_command = NULL;*/
            special_free(token);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        special_free(token);
        /*free (my_command); my_command = NULL;*/ 
    }


    return (WEXITSTATUS(status));  /*handle exit status*/
}

