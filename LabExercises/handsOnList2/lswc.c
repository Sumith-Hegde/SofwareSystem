/*
============================================================================
Name : 17a.c
Author : Sumith Hegde
Description : Write a program to execute ls -l | wc.
    a. use dup
============================================================================
*/

#include<unistd.h>

int main(void) {
    int fd[2];
    pipe(fd);
    if(fork()) {
        close(STDOUT_FILENO);
        close(fd[0]);
        dup(fd[1]);
        execl("/bin/ls", "ls", "-l", NULL);
    } else {
        close(STDIN_FILENO);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}
