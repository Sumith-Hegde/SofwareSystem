/*
============================================================================
Name : 17c.c
Author : Sumith Hegde 
Description : Write a program to execute ls -l | wc.
    a. use fcntl
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>

int main(void) 
{
    int fd[2];
    pipe(fd);
    if(!fork()) 
    {
        close(0);
        close(fd[1]);
        fcntl(fd[0], F_DUPFD, 0);
        execlp("wc", "wc", NULL);
    } 
    else 
    {
    	close(1);
        close(fd[0]);
        fcntl(fd[1], F_DUPFD, 1);
        execl("/bin/ls", "ls", "-l", NULL);
    }

    return 0;
}

