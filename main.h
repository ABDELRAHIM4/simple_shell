#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void replace_space(char *command);
void run_command(char *command);
void envi(char **environ);
int shell(void);

#endif
