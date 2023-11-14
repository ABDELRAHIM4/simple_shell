#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int simple_shell();
int main()
{
    simple_shell();
    return 0;
}

#endif /* MAIN_H */
