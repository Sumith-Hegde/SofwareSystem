/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd=open("/home/sumithhegde/order.cpp",O_RDONLY);
	int fd1=open("/home/sumithhegde/namespace.cpp",O_RDONLY);
	if(fd==-1)
	{
		printf("failed to open\n");
		return 0;
	}
	int newFd=dup(fd);
	int newFd1=dup2(newFd,fd1);
	int newFd2=fcntl(fd,F_DUPFD,7);
	printf("first - %d second - %d third - %d fourth - %d\n",fd,newFd,newFd1,newFd2);
	close(fd);
	return 0;
}
