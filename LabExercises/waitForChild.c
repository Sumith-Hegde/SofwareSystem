/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description : Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call)
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	int children[3];
	for(int i=0;i<3;i++)
	{
		int pid=fork();
		if(pid==0)
		{
			int x=i+1;
			sleep(2);
			printf("child %d completed\n",x);
			return 0;
		}
		else
		{
			children[i]=pid;	
		}
	}
//	int status;
	printf("waiting for child 3\n");
	waitpid(children[2],0,0);
	printf("child 3 completed(from parent)\n");
	return 0;
}
