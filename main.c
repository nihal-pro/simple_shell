#include "main.h"
/**
 * main - Entry point for the shell program
 * @ac : count of arguments
 * @av : arguments
 * Return: 0 (success), or status of the non_interactive_mode
 */
int main(int ac, char **av)
{
	char *len = NULL;
	char **tokens;
	/*int idx = 0;*/
	int status;
	(void)ac;
	while (1)
	{
		len = _input_len();
		/*idx ++;*/
		tokens = _spliter(len);
		if (_builtin(tokens[0]))
			handle_builtin(tokens, av, &status);
		else
			status = _execute(tokens, av);
	}
	return (status);
}
