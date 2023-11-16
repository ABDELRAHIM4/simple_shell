#include "main.h"

/**
 * envi - display environ in standard output
 *@environ: environment
 */
void envi(char **environ)
{
size_t n = 0;
while (environ[n])
{
write(STDOUT_FILENO, environ[n],  strlen(environ[n]));
write(STDOUT_FILENO, "\n", 1);
n++;
}
}
