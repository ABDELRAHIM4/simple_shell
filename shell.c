#include "main.h"
/**
 * simple_shell - reads string from user.
 * @command: character
 * @n: size of string
 * Return: string
 */
int  simple_shell()
{
ssize_t l, val;
char *command = NULL;
size_t n;
pid_t pid;
while (1)
{
write(1, "$", 1);
l = getline(&command, &n, stdin);
if (l != -1)
{
command[strcspn(command, "\n")] = '\0';
pid = fork();
if (pid == -1)
{
perror("./shell");
exit(1);
}
else if (pid == 0)
{
val = execlp(command, command, (char *)NULL);
if (val  == -1)
perror("./shell");
return (0);
}
else
{
wait(NULL);
}
}
else
{
break;
}
}
return (0);
}
