/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Find out the priority of your running program. Modify the priority with nice command
============================================================================
*/
#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{
	int priority=getpriority(PRIO_PROCESS,0);
	printf("priority of current  process is %d\n",priority);
	nice(3);
	priority=getpriority(PRIO_PROCESS,0);
	printf("priority of current process changed to  %d\n",priority);
	return 0;
}
