#include "main.h"
/**
 * ex - executes both buit ins and executable files
 * @ptr: env var
 * @pp: ptr
 */
void ex(env **ptr, char **pp)
{
int i;
int j;
int k;
char *cmd, *var;
char **args, **cmds, **te;
cmds = getcmds(ptr);
if (cmds == NULL)
{
return; }
i = 0;
while (cmds[i] != NULL)
{
k = 0;
te = init_args(cmds[i], "\n");
while (te[k] != NULL)
{
cmd = filter(te[k]);
args = getargs(cmd);
j = 0;
while(args[j] != NULL)
{
UNDO(args[j]);
++j;
}
if (_strcmp("echo", args[0]) == 0 && _strcmp("$$", args[1]) == 0)
{
var = my_itoa(getpid());
print(var);
print("\n");
free(var);
free(cmd);
_free(args); }
else if (_strcmp("env", args[0]) == 0)
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
_free(te);
my_exit(args); }
else
{
exec_built_ins(ptr, args);
free(cmd);
_free(args); }
++k; }
_free(te);
++i; }
_free(cmds); }
