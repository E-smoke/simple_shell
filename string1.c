#include "main.h"
/**
 * init_args - tokenize string into series of strings
 * @str: str to be tokenized
 * @delim: delimiter
 * Return: array of strings
 */
char **init_args(char *str, char *delim)
{
int i;
int c;
char *token;
char **arg;
c = 0;
i = 0;
while (str[i] != '\0')
{
if (str[i] == delim[0])
{
++c;
}
++i;
}
++c;
arg = (char **)malloc(sizeof(char *) * (c + 1));
if (arg == NULL)
{
return (NULL);
}
token = _strtok(str, delim);
if (token == NULL)
{
free(arg);
return (NULL);
}
for (i = 0; i < c; ++i)
{
arg[i] =(char *) malloc(sizeof(char) * (_strlen(token) + 1));
_strcpy(arg[i], (_strlen(token) + 1), token);
token = _strtok(NULL, delim);
}
arg[i] = NULL;
return (arg);
}
/**
 * strint - converts string to number
 * @str: str to be converted
 * Return: the number
 */
int strint(char *str)
{
int i;
int j;
int len;
int index;
int result;
int hund;
int number;
len = _strlen(str);
index = len - 1;
number = 0;
for (i = 0; i < len; ++i)
{
if (str[i] < '0' || str[i] > '9')
{
return (-1);
}
result = str[i] - '0';
hund = 1;
for (j = 0; j < index; ++j)
{
hund = hund * 10;
}
index = index - 1;
number = number + (result *hund);
}
return (number);
}
/**
 * _strcmp - compares two strings
 * @str1: 1st str
 * @str2: 2nd str
 * Return: 0 if the same and -1 if not the same
 */
int _strcmp(char *str1, char *str2)
{
int i;
int len1;
int len2;
if (str1 == NULL || str2 == NULL)
{
return (-1);
}
len1 = _strlen(str1);
len2 = _strlen(str2);
if (len1 != len2)
{
return (-1);
}
for (i = 0; i < len1; ++i)
{
if (str1[i] != str2[i])
{
return (-1);
}
}
return (0);
}
/**
 * fillen - get the number of chars left if cmd is filtered
 * @str: cmd
 * Return: number
 */
int fillen(char *str)
{
int i;
int start;
int c;
start = 0;
i = 0;
c = 0;
while (str[i] != '\0')
{
if (start == 1)
{
if (str[i] != ' ')
{
if (str[i - 1] == ' ')
{
++i;
c += 2;
continue;
}
++i;
++c;
continue;
}
++i;
continue;
}
else if (str[i] == ' ')
{
++i;
continue;
}
++i;
++c;
start = 1;
}
return (c);
}
