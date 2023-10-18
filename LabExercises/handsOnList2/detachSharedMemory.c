/*
============================================================================
Name : 30b.c
Author : Sumith Hegde 
Description : Write a program to create a shared memory.
c. detach the shared memory

============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main() 
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    char *data = shmat(shmid, 0, 0);
    shmdt(data);

    return 0;
}

