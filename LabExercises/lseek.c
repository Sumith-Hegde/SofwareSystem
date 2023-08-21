#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd=open("/home/sumithhegde/temp.txt",O_CREAT|O_RDWR);
	if(fd==-1)
	{
		printf("failed to open file\n");
	}
	char a[10]={'a','a','a','a','a','a','a','a','a','a'};
	//for(int i=0;i<10;i++)
	//{
		write(fd,a,10);
	//}
	int lseekOut=lseek(fd,10,SEEK_CUR);
	printf("lseek returned - %d\n",lseekOut);
	//for(int i=0;i<10;i++)
	//{
		write(fd,a,10);
	//}
	lseekOut=lseek(fd,0,SEEK_END);
	printf("lseek returned - %d\n",lseekOut);
	close(fd);
	return 0;
}
