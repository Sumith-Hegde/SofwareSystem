/*
============================================================================
Name : 21b.c
Author : Sumith Hegde
Description : Write two programs so that both can communicate by FIFO -Use two way communications.

============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() 
{
    char buff[80];
    int fd1 = open("fifo", O_RDONLY);
    
    read(fd1, buff, sizeof(buff));
    printf("The text: %s\n", buff);

    int fd2 = open("fifo2", O_WRONLY);
    printf("Enter the text: ");
    scanf("%[^\n]", buff);
    write(fd2, buff, sizeof(buff));

    return 0;
}

