#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int file1=open("/home/sumithhegde/file1",O_CREAT|O_EXCL);
	int file2=open("/home/sumithhegde/file2",O_CREAT|O_EXCL);
	int file3=open("/home/sumithhegde/file3",O_CREAT|O_EXCL);
	int file4=creat("/home/sumithhegde/file4",S_IRUSR);
	int file5=creat("/home/sumithhegde/file5",S_IRWXU);
	printf("%d %d %d %d %d\n",file1,file2,file3,file4,file5);
	while(1){}
	return 0;
}

