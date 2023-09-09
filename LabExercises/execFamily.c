/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description : Write a program to execute ls -Rl by the following system calls
 a. execl
 b. execlp
 c. execle
 d. execv
 e. execvp
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    printf("using execl:\n");
    if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) 
    {
        printf("execl failed\n");
    }

    printf("using execlp:\n");
    if (execlp("ls", "ls", "-Rl", NULL) == -1) 
    {
        printf("execlp failed\n");
    }

    printf("using execle:\n");
    char* envp[] = {NULL};
    if (execle("/bin/ls", "ls", "-Rl", NULL, envp) == -1) 
    {
        printf("execle failed\n");
    }

    printf("using execv:\n");
    char* argv[] = {"/bin/ls", "ls", "-Rl", NULL};
    if (execv("/bin/ls", argv) == -1) 
    {
        printf("execv failed\n");
    }

    printf("using execvp:\n");
    if (execvp("ls", argv) == -1) 
    {
        printf("execvp failed\n");
    }

    return 0;
}

