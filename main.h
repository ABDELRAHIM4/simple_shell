#ifndef MAIN_H
#define MAIN_H
/**
 *main - entry point
 *@command: input from user
 * Return: 0 on success, 1 on error
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void replace_space(char *command);
void run_command(char *command);



int main(void)
{
char *command;
size_t n = 0;
ssize_t l;
while (1)
{
if (isatty(STDIN_FILENO))
write(1, "$", 2);
l = getline(&command, &n, stdin);
if (l != -1)
{
command[strcspn(command, "\n")] = '\0';
run_command(command);
}
else
{
return (0);
}
free(command);
l = 0;
n = 0;
}
return (0);
}
#endif
