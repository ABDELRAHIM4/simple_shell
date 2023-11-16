#include "main.h"
/**
 *getcar() - get string
 */
char *getcar(void)
{
int n = 0;
int car;
int len = 1024;
char *line = (char *)malloc(len * sizeof(char));
if (line == NULL)
{
fprintf(stderr, "Memory allocation error.\n");
exit(1);
}
while (1)
{
car = getchar();
if (car == EOF || car == '\n')
{
break;
}
line [n] = car;
n++;
if (n + 1 == len)
{
len *= 2;
line = (char *)realloc(line, len *sizeof(char));
if (line == NULL)
{
perror("./shell");
exit(1);
}
}
}
line = '\0';
return (line);
}
