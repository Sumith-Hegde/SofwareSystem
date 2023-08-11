#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int openedFile=open("/home/sumithhegde/newFile",O_EXCL);
	printf("%d\n",openedFile);
	return 0;
}
