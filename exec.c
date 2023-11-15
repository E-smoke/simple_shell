#include "main.h"
/**
 * ex - executes both buit ins and executable files
 * @ptr: env var
 */
void ex(env **ptr, char **pp)
{
int i;
char *cmd;
char **args;
char **cmds;
cmds = getcmds(ptr);
if (cmds == NULL)
{
return; }
i = 0;
while (cmds[i] != NULL)
{
cmd = filter(cmds[i]);
args = getargs(cmd);
if (_strcmp("env", args[0]) == 0)
{
print_env(ptr);
free(cmd);
_free(args); }
else if (exec(ptr, args, pp) != -1)
{
free(cmd);
_free(args); }
else if (_strcmp("exit", args[0]) == 0)
{
frell(ptr);
free(cmd);
_free(cmds);
my_exit(args); }
else
{
exec_built_ins(ptr, args);
free(cmd);
_free(args); }
++i; }
_free(cmds); }
