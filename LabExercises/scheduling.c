/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR)
============================================================================
*/
#include<wait.h>
#include<stdio.h>
#include<sched.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	if(!fork())
	{
		int childSchedule=sched_getscheduler(0);
		int parentSchedule=sched_getscheduler(getppid());
		if(childSchedule&SCHED_FIFO)
		{
			printf("child scheduling is FIFO\n");
		}
		else
		{
			printf("child scheduling is RR\n");
		}
		if(parentSchedule&SCHED_FIFO)
		{
			printf("parent scheduling is FIFO\n");
		}
		else
		{
			printf("parent scheduling is RR\n");
		}
		struct sched_param param;
		param.sched_priority=50;
		sched_setscheduler(0,SCHED_FIFO,&param);
		childSchedule=sched_getscheduler(0);
		if(childSchedule&SCHED_FIFO)
		{
			printf("child scheduling is FIFO\n");
		}
		else
		{
			printf("child scheduling is RR\n");
		}
		sched_setscheduler(getppid(),SCHED_FIFO,&param);
		childSchedule=sched_getscheduler(0);
		if(childSchedule&SCHED_FIFO)
		{
			printf("parent scheduling is FIFO\n");
		}
		else
		{
			printf("parent scheduling is RR\n");
		}	}
	else
	{
		wait(0);
	}
	return 0;
}
