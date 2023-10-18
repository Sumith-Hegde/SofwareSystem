/*
============================================================================
Name : 28.c
Author : Sumith Hegde
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main() 
{
    printf("Maximum number of files can be opend within a process: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Size of a pipe: %ld\n", pathconf(".", _PC_PIPE_BUF));

    return 0;
}

