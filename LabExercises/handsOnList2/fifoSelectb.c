/*
============================================================================
Name : 22a.c
Author : Sumith Hegde
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() 
{
    char buff[80];
    int fd = open("fifo", O_WRONLY);
    printf("Enter the text: ");
    scanf("%[^\n]", buff);
    write(fd, buff, sizeof(buff));

    return 0;
}

