/*
============================================================================
Name : 19c.c
Author : Sumith Hegde
Description : Create a FIFO file by
    mknod system call
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int main() 
{
    printf("%d\n",mknod("fifo", S_IFIFO | 0666, 0));
    return 0;
}

