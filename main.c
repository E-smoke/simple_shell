#include "main.h"
/**
 * main - entry point
 * @argc: arg counter
 * @argv: arg vector
 * @envp: env var
 * Return: int
 */
int main(int argc, char *argv[], char *envp[])
{
int i;
env *ptr;
(void)argc;
(void)argv;
i = 1;
signal(SIGINT, handler);
ptr = NULL;
copy_env(&ptr, envp);
while (i == 1)
{
ex(&ptr, envp);
}
return (0);
}
