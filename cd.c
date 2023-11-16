#include "main.h"
/**
 * cd - to change dir
 * @ptr: environment vars
 * @args: arguments
 */
void cd(env **ptr, char **args)
{
size_t size;
char *home;
static char asp[1024];
static char prev[1024];
if (prev == NULL)
{
getcwd(prev, size);
}
if (args == NULL)
{
return;
}
else
{
if (args[1] == NULL)
{
getcwd(prev, 1024);
home = _getenv(ptr, "HOME");
chdir(home);
print(home);
print("\n");
_setenv(ptr, "PWD", home);
return;
}
if ((_strlen(args[1]) == 1) && (args[1][0] == '-'))
{
getcwd(asp, 1024);
chdir(prev);
print(prev);
print("\n");
_setenv(ptr, "PWD", prev);
_strcpy(prev, 1024, asp);
return;
}
getcwd(prev, 1024);
chdir(args[1]);
print(args[1]);
print("\n");
_setenv(ptr, "PWD", args[1]);
}
}
