#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd=open("/home/sumithhegde/order.cpp",O_RDONLY);
	if(fd==-1)
	{
		printf("failed to read\n");
		return 0;
	}
	char buffer[1000];
	while(1)
	{
		int count=0;
		while(1)
		{
			int readCount=read(fd,&buffer[count],1);
			count+=readCount;
			if(count==0||count==1000||buffer[count-1]=='\n')
			{
				break;
			}
		}
		if(count==0)
		{
			break;
		}
		write(1,buffer,count);
	}
	close(fd);
	return 0;
}
