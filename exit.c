#include "main.h"
/**
 * my_exit - implements exit cmd
 * @args: arguments
 */
void my_exit(char **args)
{
int stat;
if (args == NULL)
{
return;
}
if (args[1] == NULL)
{
_free(args);
exit(0);
}
else if (strint(args[1]) == -1)
{
return;
}
else
{
stat = strint(args[1]);
_free(args);
exit(stat);
}
}
