#ifndef MAIN_H
#define MAIN_H

#define NONE " \n\t"

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
#include <limits.h>    /* represent the limits of basic integral types CHAR_MAX, CHAR_MIN */
#include<sys/errno.h>
#include<sys/fcntl.h>

/* --- Functions used in task_01 --- */
char *_input_len(void);
char **_spliter(char *len);
char *_strdup(const char *ssd);
void special_free(char **array);
int number_args(char *len);
#endif
