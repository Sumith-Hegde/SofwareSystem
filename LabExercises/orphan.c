/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Write a program to create an orphan process
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
		printf("parent pid after orphan - %d\n",getppid());
		printf("press enter to complete child execution\n");
		/*while(1)
		{
			getchar();
			if(c=='\n')
			{
				break;
			}
		}*/
		getchar();
		printf("child execution completed\n");
	}
	else
	{
		printf("actual parent pid - %d\n",getpid());
		printf("parent execution completed\n");
		return 0;
	}
//	printf("child execution completed\n");
	return 0;
}
