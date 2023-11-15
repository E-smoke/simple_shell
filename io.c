#include "main.h"
/**
 * _getline - mimics getline
 * @bufptr: ptr to buffer
 * @n: where to store size of string
 * @fd: the file descriptor
 * Return: the string
 */
char *_getline(char **bufptr, int *n, int fd)
{
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
print("\n");
exit(1);
}
(*bufptr)[*n - 1] = '\0';
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
