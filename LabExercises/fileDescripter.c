/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int fileDesc=creat("/home/sumithhegde/newFile",S_IRWXU);
	printf("%d\n",fileDesc);
	return 0;
}
