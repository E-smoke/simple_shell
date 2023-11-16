#include "main.h"
/**
 * _getline - mimics getline
 * @bufptr: ptr to buffer
 * @n: where to store size of string
 * @fd: the file descriptor
 * Return: the string
 */
char *_getline(env **ptr,char **bufptr, int *n, int fd)
{
int i;
if (*bufptr == NULL)
{
*bufptr = (char *)malloc(1024 * sizeof(char));
}
if (*bufptr == NULL)
{
return (NULL);
}
*n = read(fd, *bufptr, 1023);
if (*n == 0)
{
frell(ptr);
free(*bufptr);
exit(0);
}
(*bufptr)[*n - 1] = '\0';
i = 0;
while ((*bufptr)[i] != '\0')
{
if ((*bufptr)[i] == '#')
{
(*bufptr)[i] = '\0';
break;
}
++i;
}
return (*bufptr);
}
/**
 * print - prints string to the stdout
 * @str: the string to print
 * Return: the number of chars printed
 */
int print(char *str)
{
int n;
n = write(STDOUT_FILENO, str, _strlen(str));
return (n);
}
