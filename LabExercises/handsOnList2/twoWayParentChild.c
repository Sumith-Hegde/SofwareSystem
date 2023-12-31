/*
============================================================================
Name : 16.c
Author : Sumith Hegde 
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
============================================================================
*/

#include<unistd.h>
#include<string.h>

int main() 
{
    int fd1[2], fd2[2], count;
    char buff[80];
    pipe(fd1);
    pipe(fd2);
    if(!fork()) 
    {
        char* msg = "Message from child.\n";
        close(fd1[1]);
        count = read(fd1[0], buff, sizeof(buff));
        write(1, buff, count);      
        close(fd2[0]);
        write(fd2[1], msg, strlen(msg));
    } 
    else 
    {
    	char* msg = "Message from parent.\n";
        close(fd1[0]);
        write(fd1[1], msg, strlen(msg));
        close(fd2[1]);
        count = read(fd2[0], buff, sizeof(buff));
        write(1, buff, count);
    }

    return 0;
}
