#include "main.h"
/**
 * replace_space - replace spaces with null characters in a given string
*@command: input from user
*/
void replace_space(char *command)
{
char *ptr;
for (ptr = command; *ptr != '\0'; ptr++)
{
if (*ptr == ' ')
*ptr = '\0';
}
}
/**
 * run_command - gets input
 *@command: input from user
 *Return: the input
*/
void run_command(char *command)
{
pid_t pid = fork();
if (strcmp(command, "exit") == 0)
{
exit(0);
}
if (pid == -1)
{
perror("./shell");
exit(1);
}
else if (pid == 0)
{
int i = 0;
char *token, *args[4];
token = strtok(command, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

replace_space(command);
if (execvp(args[0], args) == -1)
{
perror("./shell");
exit(1);
}
}
else
wait(NULL);
}

