/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Write a program to open an existing file with read write mode. Try O_EXCL flag also
============================================================================
*/
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int openedFile=open("/home/sumithhegde/newFile",O_EXCL|O_CREAT);
	printf("%d\n",openedFile);
	return 0;
}
