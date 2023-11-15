#include "main.h"
/**
 * add - adds a new node to the linked list
 * @ptr: env var
 * @var: var
 * @value: value
 */
void add(env **ptr, char *var, char *value)
{
int lenvar;
int lenval;
env *current;
lenvar = _strlen(var);
lenval = _strlen(value);
if (ptr == NULL)
{
return;
}
if (*ptr == NULL)
{
*ptr = (env *)malloc(sizeof(env));
(*ptr)->var = (char *)malloc(sizeof(char) * (lenvar + 1));
(*ptr)->value = (char *)malloc(sizeof(char) * (lenval + 1));
(*ptr)->ptr = NULL;
_strcpy(((*ptr)->var), (lenvar + 1), var);
_strcpy(((*ptr)->value), (lenval + 1), value);
return;
}
else
{
current = *ptr;
while (current->ptr != NULL)
{
current = current->ptr;
}
current->ptr = (env *)malloc(sizeof(env));
current = current->ptr;
(current)->var = (char *)malloc(sizeof(char) * (lenvar + 1));
(current)->value = (char *)malloc(sizeof(char) * (lenval + 1));
_strcpy((current->var), (lenvar + 1), var);
_strcpy((current->value), (lenval + 1), value);
current->ptr = NULL;
}
}
/**
 * copy_env - copies the envp to the linked list
 * @ptr: env var
 * @en: envp
 */
void copy_env(env **ptr, char **en)
{
int i;
char **ena;
char *temp;
i = 0;
while (en[i] != NULL)
{
temp = (char *)malloc(sizeof(char) * (_strlen(en[i]) + 1));
_strcpy(temp, (_strlen(en[i]) + 1), en[i]);
ena = init_args(temp, "=");
add(ptr, ena[0], ena[1]);
free(temp);
_free(ena);
++i;
}
}
/**
 * _getenv - mimics getenv
 * @ptr: env var
 * @var: the var you want to get it value
 * Return: the value, not malloc allocated
 */
char *_getenv(env **ptr, char *var)
{
env *current;
if (ptr == NULL || var == NULL)
{
return (NULL);
}
current = *ptr;
while (current->ptr != NULL)
{
if (_strcmp(current->var, var) == 0)
{
return (current->value);
}
else
{
current = current->ptr;
}
}
return (NULL);
}
/**
 * print_env - prints the env vars
 * @ptr: env var
 */
void print_env(env **ptr)
{
env *current;
current = *ptr;
while (current->ptr != NULL)
{
write(1, current->var, strlen(current->var));
write(1, " = ", 3);
write(1, current->value, strlen(current->value));
write(1, "\n", 1);
current = current->ptr;
}
write(1, current->var, strlen(current->var));
write(1, " = ", 3);
write(1, current->value, strlen(current->value));
write(1, "\n", 1);
}
