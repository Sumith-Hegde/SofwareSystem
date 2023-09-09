/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/sysmacros.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("specify file properly\n");
		return 0;
	}
	/*int fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("failed to open file");
	}*/
	struct stat fileInfo;
	int s=stat(argv[1],&fileInfo);
	printf("%d\n",s);
	switch(fileInfo.st_mode&S_IFMT)
	{
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFLNK:
			printf("symlink\n");
			break;
		case S_IFBLK:
			printf("block device\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
	}
	return 0;
}
