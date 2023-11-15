#include "main.h"
/**
 * main - entry point
 * @argc: arg counter
 * @argv: arg vector
 * @envp: env var
 * Return: int
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *envp[])
{
int i = 1;
env *ptr;
ptr = NULL;
copy_env(&ptr, envp);
while (i == 1)
{
printf("%s", _getenv(&ptr, "PWD"));
printf("$");
fflush(stdout);
ex(&ptr);
}
return (0);
}
