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
    if (isatty(STDIN_FILENO) == 1)/*check non interactive mode*/
        write(1, "$ ", 2);
    car = getline(&len, &len_size, stdin);
    if (car == EOF)
    {
        free (len);
        return (NULL);

        if (isatty(STDIN_FILENO) == 1)
            write(1, "\n", 1);
        perror("ERROR:");
            
        exit(EXIT_FAILURE);
    }
    return (len);
}
