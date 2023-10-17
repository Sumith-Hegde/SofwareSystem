/*
============================================================================
Name : 17b.c
Author : Sumith Hegde 
Description : Write a program to execute ls -l | wc.
    a. use dup2
============================================================================
*/

#include<unistd.h>

int main(void) 
{
    int fd[2];
    pipe(fd);
    if(fork()) 
    {
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("wc", "wc", NULL);
    } 
    else 
    {
    	close(fd[0]);
        dup2(fd[1], 1);
        execl("/bin/ls", "ls", "-l", NULL);
    }

    return 0;
}

