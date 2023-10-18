/*
============================================================================
Name : 26.c
Author : Sumith Hegde
Description : Write a program to send messages to the message queue. Check $ipcs -q

============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

struct msg 
{
	long mtype;
	char mtext[20];
} mq;
int main() 
{
    key_t key = ftok(".", 2);

    int msgid = msgget(key, IPC_CREAT | 0666);
    printf("Key: 0x%0x, msg-id: %d\n", key, msgid);

    printf("Enter msg type: ");
    scanf("%ld", &mq.mtype);
    getchar();

    printf("Enter message: ");
    scanf("%[^\n]", mq.mtext);

    int size = strlen(mq.mtext);
    msgsnd(msgid, &mq, size + 1, 0);

    return 0;
}

