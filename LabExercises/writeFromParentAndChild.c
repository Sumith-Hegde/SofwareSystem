/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the 
parent processes. Check output of the file
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int fd=open("/home/sumithhegde/parentChildWrite.txt",O_EXCL|O_CREAT|O_RDWR);
	if(!fork())
	{
		write(fd,"written from child\n",19);
	}
	else
	{
		write(fd,"written from parent\n",20);
	}
	
	return 0;
}
