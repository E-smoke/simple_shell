#include "main.h"
/**
 * handler - handles CTRL + C signal
 * @sig_num: unused
 */
void handler(int sig_num)
{
(void)sig_num;
print("\n");
}
/**
 * my_itoa - converts int to string
 * @num: the number
 * Return: the str
 */
char *my_itoa(int num)
{
int i, isNegative, temp, digits;
char *str;
temp = num;
digits = 0;
if (temp == 0)
{
digits = 1; }
else
{
while (temp != 0)
{
temp /= 10;
digits++; }}
str = (char *)malloc((digits + 1) * sizeof(char));
if (str == NULL)
{
return (NULL); }
isNegative = 0;
if (num < 0)
{
isNegative = 1;
num = -num; }
i = digits - 1;
while (num != 0)
{
str[i--] = num % 10 + '0';
num /= 10; }
if (isNegative)
{
str[0] = '-'; }
str[digits] = '\0';
return (str); }
