#include "main.h"
/**
 * _input_len - read len 
 * 
 * Description: Initializes the shell, handles user input,
 * Return: len (success), or status of the non_interactive_mode
 */
char *_input_len(void)
{
    char *len = NULL;
    size_t len_size = 0;
    ssize_t car;
    if (isatty(STDIN_FILENO) == 1)
        write(1, "$ ", 2);
    car = getline(&len, &len_size, stdin);
    if (car == EOF)
    {
        free(len);
        write(1, "\n", 1);
        perror("getline");
        exit(EXIT_FAILURE);
    }
    else
    return (len);
}
/**
 * _spliter - split len 
 * 
 * Description: Spliting the command,
 * Return: token (success), or status of the non_interactive_mode
 */
/*char *spliter(char *len)
{
    char *token;
    int i = 0;
    char **strs;
    strs = malloc(sizeof(char *) * i);
    token = strtok(len, " \n\t");
    while(token)
    {
        strs[i] = token;
        token = strtok(NULL, "\n\t");
        i++;
    }
    strs[i] = NULL;
    return (token);
    free(strs);
}*/