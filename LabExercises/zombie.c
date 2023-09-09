/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description : Write a program to create a Zombie state of the running program
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	if(!fork())
	{
		printf("child(pid - %d) execution completed. Now i will become Zombie!!\n",getpid());
		exit(0);
	}
	else
	{
		while(1)
		{
		}
	}
	return 0;
}
