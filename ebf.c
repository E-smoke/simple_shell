#include "main.h"
/**
 * getcmds - gets cmd
 * Return: series of cmds separated by ;
 */
char **getcmds()
{
int n;
char **cmds;
char *input = NULL;
_getline(&input, &n, 0);
cmds = init_args(input, ";");
free(input);
return (cmds);
}
/**
 * getargs - getargs
 * @cmd: cmd
 * Return: arguments fo cmd
 */
char **getargs(char *cmd)
{
char **args;
if (cmd == NULL)
{
return (NULL);
}
args = init_args(cmd, " ");
return (args);
}
/**
 * getpath - gets the path var
 * @ptr: env vars
 * Return: series of path
 */
char **getpath(env **ptr)
{
char *pathc;
char *path;
char **pathptr;
pathc = _getenv(ptr, "PATH");
path = (char *)malloc(sizeof(char) * (_strlen(pathc) + 1));
_strcpy(path, (_strlen(pathc) + 1), pathc);
pathptr = init_args(path, ":");
free(path);
return (pathptr);
}
/**
 * exec - executes already existing cmds
 * @ptr: env vars
 * @args: arguments
 * Return: 0 on sucess and -1 on error
 */
int exec(env **ptr, char **args)
{
int i;
int len;
int stat;
char **pathptr;
char *path;
char *cmd = NULL;
pathptr = getpath(ptr);
cmd = _strcat("/", args[0]);
i = 0;
len = -1;
while (pathptr[i] != NULL)
{
if (args[0][0] == '/' || args[0][0] == '.')
{
path = (char *)malloc(sizeof(char) * (_strlen(args[0]) + 1));
_strcpy(path, (_strlen(args[0]) + 1), args[0]); }
else
{
path = _strcat(pathptr[i], cmd); }
if (access(path, F_OK) == 0)
{
len = fork();
if (len == 0)
{
execve(path, args, NULL);
}
else
{
wait(&stat);
break;
}
}
free(path);
++i;
}
if (pathptr[i] != NULL)
{
free(path);
}
free(cmd);
_free(pathptr);
return (len);
}

