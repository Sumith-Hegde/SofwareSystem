/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Write a program, call fork and print the parent and child process id
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
int main()
{
	if(!fork())
	{
		printf("pid of child - %d\n",getpid());
		printf("pid of parent seen from child - %d\n",getppid());
	}
	else
	{
		printf("pid of parent - %d\n",getpid());
		wait(0);
	}
	return 0;
}

