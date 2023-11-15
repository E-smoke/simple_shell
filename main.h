#ifndef MAIN_H
#define MAIN_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * struct ll - linked list
 * @var: var
 * @value: value
 * @ptr: env ptr
 */
typedef struct ll
{
char *var;
char *value;
struct ll *ptr;
} env;
/**
 * struct bi - built ins struct
 * @cmd: cmd name
 * @fp: ptr to function
 */
typedef struct bi
{
char *cmd;
void (*fp)(env **ptr, char **args);
} bic;
char *_strtok(char *str, const char *delim);
int _strlen(char *str);
int _strcpy(char *dest, int lend, char *src);
char *_strcat(char *dest, char *src);
char **init_args(char *str, char *delim);
int strint(char *str);
void _free(char **strptr);
char *_getline(char **bufptr, int *n, int fd);
int print(char *str);
char **getargs(char *cmd);
char **getpath(env **ptr);
int exec(env **ptr, char **args, char **p);
void my_exit(char **args);
void exec_built_ins(env **ptr, char **args);
void ex(env **ptr, char **pp);
void cd(env **ptr, char **args);
int _strcmp(char *str1, char *str2);
char **getcmds();
int fillen(char *str);
char *filter(char *str);
void add(env **ptr, char *var, char *value);
void copy_env(env **ptr, char **en);
char *_getenv(env **ptr, char *var);
void print_env(env **ptr);
void frell(env **head);
void _setenva(env **ptr, char **args);
void _setenv(env **ptr, char *args1, char *args2);
void _unsetenv(env **ptr, char **args);
void handler(int sig_num);
#endif
