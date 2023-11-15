#include "main.h"
/**
 * filter - to filter cmd
 * @str: string to be filtered
 * Return: filtered string, malloc allocated
 */
char *filter(char *str)
{
int i;
int start;
int len;
int c;
char *filter;
start = 0;
i = 0;
c = 0;
len = fillen(str);
filter = (char *)malloc(sizeof(char) * (len + 1));
while (str[i] != '\0')
{
if (start == 1)
{
if (str[i] != ' ')
{
if (str[i - 1] == ' ')
{
filter[c] = ' ';
++c;
filter[c] = str[i];
++c;
++i;
continue; }
filter[c] = str[i];
++c;
++i;
continue; }
++i;
continue; }
else if (str[i] == ' ')
{
++i;
continue; }
filter[c] = str[i];
++c;
++i;
start = 1; }
filter[c] = '\0';
return (filter); }
