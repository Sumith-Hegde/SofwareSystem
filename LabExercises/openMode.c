#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
int main()
{
	int fd=open("/home/sumithhegde/temp.txt",O_CREAT|O_RDWR);
	if(fd==-1)
	{
		printf("failed to open \n");
	}
	int modes=fcntl(fd,F_GETFL);
	printf("access mode - \n");
	if((modes&O_RDWR)==O_RDWR)
	{
		printf("read write mode\n");
	}
	if((modes&O_RDONLY)==O_RDONLY)
	{
		printf("read only mode\n");
	}
	if((modes&O_WRONLY)==O_WRONLY)
	{
		printf("write only mode\n");
	}
	return 0;
}
