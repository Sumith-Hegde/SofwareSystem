/*
============================================================================
Name : 32d.c
Author : Sumith Hegde
Description :Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore

============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

 union semun 
 {
        int val;
} arg;
int main() 
{ 
    key_t key = ftok(".", 1);
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0600);
    if(semid != -1) 
    {
        arg.val = 1;
        semctl(semid, 0, SETVAL, arg);
    } 
    else 
    {
        semid = semget(key, 1, 0600);
    }
    
    semctl(semid, 0, IPC_RMID);

    return 0;
}

