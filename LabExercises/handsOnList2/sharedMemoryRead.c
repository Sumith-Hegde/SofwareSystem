/*
============================================================================
Name : 30aa.c
Author : Sumith Hegde 
Description : Write a program to create a shared memory.
aa. read data from the shared memory

============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main() 
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0600);

    char *data = shmat(shmid, 0, 0);
    printf("Text from shared memory: %s\n", data);

    return 0;
}

