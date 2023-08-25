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
	printf("first - %d second - %d third - %d ",fd,newFd,newFd1);
	close(fd);
	return 0;
}
