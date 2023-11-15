#include "main.h"
/**
 * replace_space - replace spaces with null characters in a given string
 * run_command - make another process by fork() and run the command
 * Return 0: if pid = 0
 * Return -1:if pid = -1
 * else : wait
 * @command: input from user
 **/
void replace_space(char *command)
{
char *ptr;
for (ptr = command; *ptr != '\0'; ptr++)
{
if (*ptr == ' ')
*ptr = '\0';
}
}
void run_command(char *command)
{
pid_t pid = fork();
int i = 0;
if (pid == -1)
{
perror("./shell");
exit(1);
}
else if (pid == 0)
{
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
