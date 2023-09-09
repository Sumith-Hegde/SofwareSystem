/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int linkCreated=symlink("/home/sumithhegde/date.cpp","/home/sumithhegde/dtlinkSoft");
	if(linkCreated==0)
	{
		printf("softlink created");
	}
	else
	{
		printf("error!");
	}
	int hardLinkCreated=link("/home/sumithhegde/date.cpp","/home/sumithhegde/dtlinkHard");
	if(hardLinkCreated==0)
	{
		printf("hardlink created");
	}
	else
	{
		printf("error!");
	}
	int pipe=mkfifo("/home/sumithhegde/namedPipe",0666);
	if(pipe==0)
	{
		printf("pipe created");
	}
	else
	{
		printf("error!");
	}



	return 0;

}
