/*
============================================================================
Name : 29.c
Author : Sumith Hegde
Description : Write a program to remove the message queue.

============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

struct msg 
{
        int mtype;
        char mtext[20];
} mq;
int main() 
{
    
    key_t key = ftok(".", 2);
    int msgid = msgget(key, 0);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}


