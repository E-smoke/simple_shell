#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
char buf[1024];
char *args[] = {"/bin/ls", NULL};
char *envp[] = {"LC_COLLATE=en_US.UTF-8", NULL};
write(1, "$ ", 2);
fflush(stdout);
read(0, buf, 1023);
execve("/bin/ls", args, envp);
return (1);
}
