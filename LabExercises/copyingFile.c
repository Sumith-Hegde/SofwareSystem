/*
============================================================================
Author : Sumith Ramakrishna Hegde
Description :  Write a program to copy file1 into file2 ($cp file1 file2)
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("%d\n",argc);
		printf("specify source and destination\n");
		return 0;
	}
	int readFile=open(argv[1],O_RDONLY);
	int writeFile=open(argv[2],O_WRONLY|O_CREAT);
	if(readFile==-1||writeFile==-1)
	{
		printf("Failed to open\n");
	}
	else
	{
		while(1)
		{
			char buffer;
			int charRead=read(readFile,&buffer,1);
			if(charRead==0)
			{
				break;
			}
			int charWritten=write(writeFile,&buffer,1);
		}
		int closeRead=close(readFile);
		int closeWrite=close(writeFile);
		if(closeRead==-1||closeWrite==-1)
		{
			printf("Failed to Close\n");
		}
	}
	return 0;
}
	
