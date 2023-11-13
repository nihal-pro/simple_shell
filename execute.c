#include "main.h"

int _execute(char **token, char **argv)
{
    int status = 0;
    pid_t pid;

    pid = fork();
    if(pid == EOF)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(pid == 0)
    {
        if(execve(token[0], token, environ) == -1)
        {
            perror(argv[0]); /*perror("execve") -> execve : no such file or directory perror("argv[0]") -> ./file : no..*/
            exit(EXIT_FAILURE);
            special_free(token);
        }
    }
    waitpid(pid, &status, 0);
    special_free(token);


    return (WEXITSTATUS(status));   
}