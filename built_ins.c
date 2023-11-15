#include "main.h"
/**
 * exec_built_ins - executes built in cmds
 * @ptr: env vars
 * @args: arguments
 */
void exec_built_ins(env **ptr, char **args)
{
int i;
bic built_ins[] = {
{"cd", cd},
{"unsetenv", _unsetenv},
{"setenv", _setenva},
{NULL, NULL}
};
i = 0;
while ((built_ins[i]).cmd != NULL)
{
if (_strcmp((built_ins[i]).cmd, args[0]) == 0)
{
(built_ins[i]).fp(ptr, args);
break;
}
++i;
}
}
