#include "main.h"
/**
 * frell - free entire linked list
 * @head: env var
 */
void frell(env **head)
{
env *current = *head;
while (current != NULL)
{
env *temp = current;
current = current->ptr;
free(temp->var);
free(temp->value);
free(temp);
}
*head = NULL;
}
/**
 * _setenva - implements setenv for args
 * @ptr: env var
 * @args: arguments
 */
void _setenva(env **ptr, char **args)
{
env *current;
current = *ptr;
while (current->ptr != NULL)
{
if (_strcmp(current->var, args[1]) == 0)
{
free(current->value);
current->value = (char *)malloc(sizeof(char) * (_strlen(args[2]) + 1));
_strcpy(current->value, (_strlen(args[2]) + 1), args[2]);
return;
}
current = current->ptr;
}
add(ptr, args[1], args[2]);
}
/**
 * _setenv - implements setenv
 * @ptr: env var
 * @args1: var
 * @args2: value
 */
void _setenv(env **ptr, char *args1, char *args2)
{
env *current;
current = *ptr;
while (current->ptr != NULL)
{
if (_strcmp(current->var, args1) == 0)
{
free(current->value);
current->value = (char *)malloc(sizeof(char) * (_strlen(args2) + 1));
_strcpy(current->value, (_strlen(args2) + 1), args2);
return;
}
current = current->ptr;
}
add(ptr, args1, args2);
}
/**
 * _unsetenv - implements unsetenv for args
 * @ptr: env var
 * @args: arguments
 */
void _unsetenv(env **ptr, char **args)
{
env *current;
env *csp;
current = *ptr;
while (current->ptr != NULL)
{
if (_strcmp(current->var, args[1]) == 0)
{
free(current->var);
free(current->value);
csp->ptr = current->ptr;
free(current);
return;
}
csp = current;
current = current->ptr;
}
}
