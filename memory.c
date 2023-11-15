#include "main.h"
/**
 * _free - frees array of strings
 * @strptr: ptr to array of strings
 */
void _free(char **strptr)
{
int i;
if (strptr == NULL)
{
return;
}
i = 0;
while (strptr[i] != NULL)
{
free(strptr[i]);
i++;
}
free(strptr);
}
