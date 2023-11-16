#include "main.h"
/**
 * _strlen - get str len
 * @str: str
 * Return: len
 */
int _strlen(char *str)
{
int len;
if (str == NULL)
{
return (-1);
}
len = 0;
while (str[len] != '\0')
{
++len;
}
return (len);
}
/**
 * _strcpy - coppies string
 * @dest: dest str
 * @lend: size of dest str
 * @src: src
 * Return: len of dest str
 */
int _strcpy(char *dest, int lend, char *src)
{
int i;
int lens;
lens = _strlen(src);
if ((lend < (lens + 1)) || (src == NULL) || (dest == NULL))
{
return (-1);
}
else
{
for (i = 0; i <= lens; ++i)
{
dest[i] = src[i];
}
}
return (i - 1);
}
/**
 * _strcat - append one str to another
 * @dest: dest string
 * @src: src string
 * Return: the appended str, malloc allocated
 */
char *_strcat(char *dest, char *src)
{
int i;
int lend;
int lens;
char *str;
lend = _strlen(dest);
lens = _strlen(src);
if (src == NULL && dest == NULL)
{
return (NULL);
}
if (src == NULL)
{
str = (char *)malloc(sizeof(char) * (lend + 1));
_strcpy(str, (lend + 1), dest);
return (str);
}
if (dest == NULL)
{
str = (char *)malloc(sizeof(char) * (lens + 1));
_strcpy(str, (lens + 1), src);
return (str);
}
str = (char *)malloc(sizeof(char) * (lens + lend + 1));
_strcpy(str, (lend + 1), dest);
for (i = lend; i < (lens + lend + 1); ++i)
{
str[i] = src[i - lend];
}
return (str);
}
/**
 * _strtok - tokenize str
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: token
 */
char *_strtok(char *str, const char *delim)
{
static char *token;
static char *start;
int i = 0;
if (str != NULL)
{
token = str;
while (!((token[i] == delim[0]) || (token[i] == '\0')))
{
i++; }
if (i == 0)
{
return (NULL); }
if (token[i] == delim[0])
{
token[i] = '\0';
start = token + i + 1;
return (token); }
else
{
start = NULL;
return (token); }}
else
{
if (start == NULL)
{
return (NULL); }
token = start;
i = 0;
while (!((token[i] == delim[0]) || (token[i] == '\0')))
{
i++; }
if (i == 0)
{
return (NULL); }
if (token[i] == delim[0])
{
token[i] = '\0';
start = token + i + 1;
return (token); }
else
{
start = NULL; }}
return (token); }
