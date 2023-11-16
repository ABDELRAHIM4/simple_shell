#include "main.h"
/**
 *main - entry point
 * Return: 0 on success, 1 on error
 */


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
if (command != NULL)
free(command);

return (0);
}
l = 0;
n = 0;
}
return (0);
}
