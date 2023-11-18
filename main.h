#ifndef MAIN_H
#define MAIN_H

#define NONE " \n\t"
extern char **environ;
/* --- headers file --- */
#include <stdio.h>	   /* stdin using in getline */
#include <unistd.h>	   /* for write and execve function */
#include <sys/types.h> /* for get process pid_t and size_t */
#include <sys/wait.h>  /* wait function */
#include <stdlib.h>	   /* exit and free function */
#include <string.h>	   /* strlen strtok function */
#include <sys/stat.h>  /* stat function */
#include <signal.h>	   /* for signal function */
#include<stddef.h>     /* for NULL */
#include <limits.h>    /* represent*/
#include<sys/errno.h>
#include<sys/fcntl.h>

/*--- Functions used in task_01_02*/
char *_input_len(void);
char **_spliter(char *len);
char *_strdup(const char *ssd);
void special_free(char **array);
int number_args(char *len);
/*int _execute(char **token, char **argv, int INDEX);*/
int _execute(char **token, char **argv);
char *_getenv(char *env);
int _strcmp(char *s1, char *s2);
int _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_getpath(char *command);
void handle_error(char *shell_name, char *comnd, int INDEX);
char *_atoi(int x);
void reverse_str(char *str, int len);
char *print(char *str);
int _builtin(char *my_command);
void _env(char **my_command, int *status);
/*void shell_exit(char **my_command, int *status);*/
void shell_exit(char **my_command, char **argv, int *status, int idx);
void handle_builtin(char **my_command, char **av, int *status);
int positif_number(char *str);
int _itoa(char *str);

#endif
